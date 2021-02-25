#include <bits/stdc++.h>
using namespace std;
//���� ������ �Ǵ� �� �ܰ� ��ǥ�� ������
// ���� �ܰ����� �Ÿ� ���ؼ� �ִ� �Ÿ� ���ϱ� 
int n,land_lable=0;
int land[101][101]={0,};// 0 : �ٴ� , -1: �� -> 1,2,3.. : �� �׷� ��ȣ 
int dist[101][101]; // -1: �湮��, 0 �̻� �湮�߰� �Ÿ� 
int group[101][101]; // dist�� �׷� ����  
int dx[4] = {0,-1,1,0}, dy[4] = {-1,0,0,1};


void Input(){
		//�Է� 
	cin >> n;
	for(int i = 0,tmp;i<n;i++){
		for(int j = 0 ; j < n;j++){
			scanf("%1d",&tmp);
			if(tmp) land[i][j] = -1;
		}
	}
}

//void Make_LandLable(int a,int b,int cnt){
//	queue<pair<int,int>> q;
//	q.push({a,b});
//	while(!q.empty()){
//		int y = q.front().first;
//		int x = q.front().second;
//		q.pop();
//		land[y][x] = cnt;
//		group[y][x] = cnt; // �� �׷� ��ȣ 
//		for(int i = 0 ; i<4 ; i++){
//			int nx = x + dx[i] , ny = y+dy[i];
//			if(ny<0 || ny>=n || nx<0 || nx>=n || land[ny][nx] !=-1) continue;
//			q.push({ny,nx});
//		}
//	}
//}

void Make_LandLable(int a,int b,int cnt){
	queue<pair<int,int>> q;
	q.push({a,b});
	land[a][b] = cnt;
	group[a][b] = cnt; // �� �׷� ��ȣ 	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i = 0 ; i<4 ; i++){
			int nx = x + dx[i] , ny = y+dy[i];
			if(ny<0 || ny>=n || nx<0 || nx>=n || land[ny][nx] !=-1) continue;
			q.push({ny,nx});
			land[ny][nx] = cnt;
			group[ny][nx] = cnt; // �� �׷� ��ȣ 
		}
	}
}


void Min_Distace(){
	queue<pair<int,int>> q;
	
	//�� ��ǥ��  q�� �ְ� 
	for(int i = 0 ; i< n ; i++){
		for(int j=0; j<n;j++){
			if(land[i][j]>0){//���̶�� 
				dist[i][j] = 0;//land�� dist�� 0 
				q.push({i,j});
			}
		}
	} 
	
	int ans = 3*n ;	
	//land�� q �̿��� dist �� ä��� 
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i = 0 ; i< 4 ;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
			
			if( dist[ny][nx] == -1 ) {
				//�湮 �� , ������ �ٴٸ� �ɸ�, ������ land�� �� 0���� �ؼ�
				dist[ny][nx] = dist[y][x]+1;
				group[ny][nx] = group[y][x];
				//�ٽ� q�� �־������ 
				q.push({ny,nx});
				
			}
			//�湮 �̹� �߰� �׷� �ٸ� ���
			if( dist[ny][nx] != -1 && group[ny][nx] != group[y][x]){
				ans = min(dist[ny][nx] + dist[y][x] , ans);
			}
		}
	}

//	for(int i = 0 ; i < n ; i++){
//		for(int j = 0 ; j < n ; j++){
//			for(int k = 0 ; k < 4 ; k++){
//				int nx = j + dx[k];
//				int ny = i + dy[k];
//				if(ny<0 || ny>=n || nx<0 || nx>=n) continue;
//				if(group[i][j] != group[ny][nx]){
//					ans = min(dist[ny][nx] + dist[i][j] , ans);
//				}
//				
//			}
//		}
//	}
	
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	Input();


	//�� �׷� ����� 
	for(int i = 0;i<n;i++)
		for(int j = 0 ; j < n;j++)
			if(land[i][j]==-1)	Make_LandLable(i,j,++land_lable);		
		
			
	memset(dist,-1, sizeof(dist));//�湮�� -1 

	//�ٴٿ��� ���� ���������� �Ÿ� , ������ �������� �Ÿ� 
	Min_Distace(); 	

	return 0;
}
