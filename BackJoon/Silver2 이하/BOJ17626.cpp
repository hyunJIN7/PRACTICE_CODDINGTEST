// https://ongveloper.tistory.com/261
// https://codecollector.tistory.com/701
#include <bits/stdc++.h>
#define MAX 50001

using namespace std;

vector<int> dp(MAX,0x7f7f7f7f);
int N;

void MakeSquares(int n){	
	for(int i =1; i*i <= n ; i++){
		dp[n] = min(dp[n], dp[i*i] + dp[n-i*i]);
	}	
} 

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>N;
	dp[0]=0;
	
	for(int i = 1; i*i <= N ; i++){
		dp[i*i] = 1;
	}
	
	for(int i = 1 ; i <= N ; i++){
		MakeSquares(i);	
	}
	
	cout<<dp[N];
}



