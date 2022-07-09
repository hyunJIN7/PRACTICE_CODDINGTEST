// 시간 초과 : 이건 dp지 dfs가 아님, 
//solution에서 solution 다시 호출하려면 방문했는지 체크해야해 
 
#include <iostream>
#include <algorithm>
#define MAX 1005
using namespace std;

int N,M;
int candy[MAX][MAX];
int dp[MAX][MAX]={0,};

void Input(){
	cin>>N>>M;
	for(int i = 1; i<= N; i++){
		for(int j = 1 ; j <= M ; j++){
			cin>>candy[i][j];
		}
	}
}

void Solution(int y, int x){ //현재 위치, 이전 위치 누적 사탕 수  
	if(y > N || x > M) return;
 	dp[y][x] = max(dp[y-1][x],dp[y][x-1])+candy[y][x];
}

void Solve(){
	Input();
	dp[1][1] = candy[1][1];
	for(int i = 1; i<= N; i++){
		for(int j = 1 ; j <= M ; j++){
			Solution(i,j);
		}
	}
	cout<<dp[N][M];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	Solve();
}
