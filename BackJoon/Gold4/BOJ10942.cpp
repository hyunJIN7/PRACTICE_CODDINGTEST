#include <bits/stdc++.h>

#define MAX_N 2000

using namespace std;

int N, M;
int input[MAX_N];
int dp[MAX_N][MAX_N] = {0,};

int Palindrome(int start, int end){
	//이미 구했다면 
	if(dp[start][end]) return dp[start][end];
	
	if(start == end){
		dp[start][end] = 2;
		return 2; 
	} 
	
	if(start + 1 == end){
		if(input[start] == input[end]){
			dp[start][end] = 2;
			return 2;
		} 
		dp[start][end] = 1;	
		return 1;
	}
	
	if(input[start] != input[end]){
		dp[start][end] = 1;	
		return 1;
	}
		
	return dp[start][end] = Palindrome(start+1, end-1);	
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	for(int i = 0 ; i < N ; i++) cin >> input[i];
	
	memset(dp, 0, sizeof(dp));
	
	for(int i = 0 ; i < N ; i++){
		for(int j = i; j < N; j++){
			if(!dp[i][j]) Palindrome(i,j);
		}	
	}
	
	cin >> M;
	while(M--){
		int l,r;
		cin >> l >> r;
		cout << dp[l-1][r-1] - 1<<"\n";
		
	}
	return 0;
}
