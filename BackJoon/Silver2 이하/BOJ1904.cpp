#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N;
ll dp[10000010]={0,};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>N;
	
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	for(int i = 4; i <= N ; i++){
		dp[i] = (dp[i-1]+dp[i-2])%15746 ;
	}
	cout<<dp[N];
}
