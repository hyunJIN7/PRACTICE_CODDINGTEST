#include <bits/stdc++.h>
using namespace std;
char land[51][51];
bool visited[51][51]={0,};
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int h,w,ans=0;
struct treasure{
	int y,x,d;
};

void Input(){
	cin >> h >>w;
	for(int i = 0 ; i < h;i++){
		for(int j = 0 ; j < w;j++){
			cin>>land[i][j];
		}
	}
}

void BFS(int a,int b){
	queue<treasure> q;
	q.push({a,b,0});
	visited[a][b] = true; // for 돌기전에 true로 해야 다시 돌아오지 않음  
	while(!q.empty()){
		treasure cp = q.front();	
		q.pop();
		
		for(int i =0 ; i<4 ;i++){
			int y = cp.y+dy[i];
			int x = cp.x+dx[i];
			
			if(y<0 || y >= h || x < 0 ||x >=w) continue;
			if(land[y][x] == 'W'||visited[y][x] ) continue;
			
			visited[y][x]=true; 
			ans = max(ans,cp.d+1);
			q.push({y,x,cp.d+1});
		}	
	}
}

void Solution(){
	for(int i = 0 ; i < h;i++){
		for(int j = 0 ; j < w;j++){
			if(land[i][j]=='L') {
				BFS(i,j);
				memset(visited,0,sizeof(visited));
			}			
		}
	}
	cout<<ans;
}

void Slove(){
	Input();
	Solution();
} 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	Slove();		
	
}
