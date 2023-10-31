#include <bits/stdc++.h>

#define MAX 1000
#define BLOCK_NUM 3
#define INF 987654321

using namespace std;

int N;
int block[MAX] = {0,};
int dp[MAX] = {0,};

int main(){
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> N;
		
	for(int i = 0 ; i < N ; i++){
		char c; cin >> c;
		if( c == 'B') block[i] = 0;
		else if( c == 'O') block[i] = 1;
		else block[i] = 2;
	}

	fill(dp,dp+N,INF);
	dp[0] = 0;
	for(int i = 1; i < N; i++){ // 현재 
		for(int j = 0; j < i ; j++){ // 이전  
			if( (block[j] + 1) % BLOCK_NUM != block[i]) continue;
			dp[i] = min(dp[i] , dp[j] + (i-j)*(i-j));
	
		}
	}

	if(dp[N-1] == INF) dp[N-1] = -1;
	cout<<dp[N-1];
	return 0;	
}
