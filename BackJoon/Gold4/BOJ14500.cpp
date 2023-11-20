#include <bits/stdc++.h>

#define MAX 500
#define DIR_NUM 4
#define BLOCK_SIZE 4

using namespace std;

int N, M;
int grid[MAX][MAX];
vector<pair<int,int>> curr_visit;

int answer = 0;

int dy[DIR_NUM] = {0,0,1,-1};
int dx[DIR_NUM] = {1,-1,0,0};

bool InRange(int y,int x){ return 0 <= y && y < N && 0 <= x && x < M;}

bool CanGo(int y, int x){
	if(!InRange(y,x) ) return false;
	for(int i = 0 ; i < curr_visit.size(); i++){
		pair<int,int> pos = {y,x};
		if( pos == curr_visit[i]) return false;
	}
	return true;	
}

void SearchBlock(int cnt){
	if(cnt == BLOCK_SIZE){
		int sum = 0;
		for(int i = 0 ; i < BLOCK_SIZE; i++){
			int cy, cx;
			tie(cy,cx) = curr_visit[i];
			sum += grid[cy][cx];
		} 	
		answer = max(sum,answer);
		return;
	}
	
	for(int i = 0 ; i < curr_visit.size(); i++){
		int cy, cx;
		tie(cy,cx) = curr_visit[i];
		for(int d = 0 ; d < DIR_NUM; d++){
			int ny = cy + dy[d] , nx = cx + dx[d];
			if(!CanGo(ny,nx)) continue;
			curr_visit.push_back({ny,nx});
			SearchBlock(cnt + 1);
			curr_visit.pop_back();
		}
		
	}	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < M ; j++)
			cin >> grid[i][j];
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			curr_visit.push_back({i,j});
			SearchBlock(1);
			curr_visit.pop_back();
		}
		
	}
	
	cout << answer ;
		 
}
