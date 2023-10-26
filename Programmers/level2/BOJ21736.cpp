#include <bits/stdc++.h>

#define MAX 600
#define DIR_NUM 4
#define WALL 'X'
#define People 'P'

using namespace std;

int N,M;
char campus[MAX][MAX];

int iy,ix; // 도연이 현재 위치  

int dy[DIR_NUM] = {0,0,-1,1};
int dx[DIR_NUM] = {-1,1,0,0};

bool visited[MAX][MAX] = {0,};

int ans = 0;

bool InRange(int y, int x){
	return 0 <= y && y < N && 0 <= x && x < M; 
}

void BFS(){
	queue<pair<int,int>> q;
	visited[iy][ix] = true;
	q.push({iy,ix});
	
	while(!q.empty()){
		int cy,cx;
		tie(cy,cx) = q.front();
		q.pop();
		
		for(int d = 0 ; d < DIR_NUM; d++){
			int ny = cy + dy[d], nx = cx + dx[d];
			if(!InRange(ny,nx) || visited[ny][nx] || campus[ny][nx] == WALL) continue;
			if(campus[ny][nx] == People) ans++;
			visited[ny][nx] = true;
			q.push({ny,nx});
		}
		
	}
	
	
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N >> M;
	for(int i = 0 ; i < N ; i++){
		string input;
		cin >> input;
		for(int j = 0 ; j < M ; j++){
			campus[i][j] = input[j];
			if(input[j] == 'I')
				iy = i, ix = j;
		}		
	}
	
	BFS();
	
//	cout<< (ans)? ans : "TT";
	if(ans) cout<<ans;
	else cout << "TT";
	
	return 0;	
}
