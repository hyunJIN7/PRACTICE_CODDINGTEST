#include <bits/stdc++.h>

#define MAX 50
#define DIR_NUM 2

using namespace std;

int N;
int grid[MAX][MAX];

int answer = 0;

int dy[DIR_NUM] = {1, 0};
int dx[DIR_NUM] = {0, 1};

bool InRange(int y,int x){ return 0 <= y && y < N && 0 <= x && x < N;}

int ans = 0;

int CountMaxCnt(int y, int x, int dir){ // dir 0 세로 ,dir 1 가로  
	//해당 위치의 시작 부분 부터  
	if(!dir) y = 0;
	else x = 0;
	
	int max_cnt = 0;
	int target = grid[y][x]; 
	int cnt = 1;
	
	for(int i = 1 ; i < N ; i++){
		int ny = y + dy[dir] * i, nx = x + dx[dir]*i;
		cnt = (target == grid[ny][nx])? cnt + 1 : 1;
		max_cnt = max(max_cnt,cnt);
		target = grid[ny][nx]; 
	}
	
	return max_cnt;
}

void Swap(int y1,int x1, int y2,int x2){
	int tmp = grid[y1][x1];
	grid[y1][x1] = grid[y2][x2];
	grid[y2][x2] = tmp;
}

void Simulate(int y ,int x, int dir){	
	//바꿀 위치  
	int ny = y + dy[dir], nx = x + dx[dir]; 
	if(!InRange(ny,nx)) return;
	
	ans = max(ans,CountMaxCnt(y,x,dir));	
	//자리 이동  
	Swap(y,x,ny,nx);
	ans = max(ans,CountMaxCnt(y,x,dir));
	
	ans = max(ans,CountMaxCnt(y,x,!dir));
	ans = max(ans,CountMaxCnt(ny,nx,!dir));
	
	Swap(y,x,ny,nx);// 원래 대로  
}
void Solve(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			Simulate(i,j,0);
			Simulate(i,j,1);
			if(ans == N) return;
		}
	}	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			char c; 
			cin >> c;
			if( c == 'C') grid[i][j] = 0;
			else if( c == 'P') grid[i][j] = 1;
			else if( c == 'Z') grid[i][j] = 2;
			else grid[i][j] = 3;
		}
	}
	Solve();
		
	cout << ans; 
}
