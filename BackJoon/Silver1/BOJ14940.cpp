#include <bits/stdc++.h>
#define endl "\n"
#define MAX 1001
using namespace std;

int H,W;
int board[MAX][MAX];
int dist[MAX][MAX];

queue<pair<int,int>> que;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>H>>W;
	for(int i = 0 ; i < H ;i++){
		for(int j = 0 ; j < W ; j++){
			dist[i][j]=-1;
			
			cin>>board[i][j];
			if(board[i][j]==2){
				que.push({i,j});
				dist[i][j]=0;
			}
		}
	}

	while(!que.empty()){
		auto cur = que.front();
		que.pop();
		for(int i = 0 ; i < 4; i++){
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
			if(!board[ny][nx] || dist[ny][nx]!=-1) continue;
		
			dist[ny][nx] = dist[cur.first][cur.second] + 1;
			que.push({ny,nx});
		
		}
		
	}
	
	for(int i = 0 ; i < H ;i++){
		for(int j = 0 ; j < W ; j++){
			if(!board[i][j]) cout<<"0 ";
			else cout<<dist[i][j]<<" ";
			

		}
		cout<<endl;
	}
	
}
