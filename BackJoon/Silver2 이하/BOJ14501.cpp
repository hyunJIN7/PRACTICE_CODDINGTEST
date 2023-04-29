#include <bits/stdc++.h>
//https://dinist.tistory.com/30
using namespace std;

int T[18],P[18],dp[18]={0,};

int max(int a, int b){
	if(a<b) return b;
	return a;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N;
	cin>>N;
	for(int i = 1 ; i <= N ; i++){
		cin>>T[i]>>P[i];
	}
	
	for(int i = N ; i > 0 ; i-- ){
		if(N+1 < i+T[i] ) dp[i]=dp[i+1];
		else dp[i] = max(dp[i+1], P[i]+dp[i+T[i]]);
	}
	
	cout<<dp[1];
}
