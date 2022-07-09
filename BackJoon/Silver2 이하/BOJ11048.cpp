// �ð� �ʰ� : �̰� dp�� dfs�� �ƴ�, 
//solution���� solution �ٽ� ȣ���Ϸ��� �湮�ߴ��� üũ�ؾ��� 
 
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

void Solution(int y, int x){ //���� ��ġ, ���� ��ġ ���� ���� ��  
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
