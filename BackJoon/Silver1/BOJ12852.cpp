#include <bits/stdc++.h>
#define MAX 1000002
using namespace std;
int dp[MAX], pre[MAX]={0,};

int n;
string ans;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >>n;
	
	ans = to_string(n);
	dp[1]=0; pre[1]=0;
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] +1;
		pre[i] = i -1;
		
		if( i%3==0 and dp[i/3] + 1 < dp[i] ){
			dp[i] = dp[i/3]+1;
			pre[i] = i/3;
		}
		if( i%2 ==0 and dp[i/2]+1<dp[i]){
			dp[i] = dp[i/2]+1;
			pre[i]=i/2;
		}
	}

	cout<<dp[n]<<"\n";
	ans = to_string(n);
	for(int i=n; i>1;i=pre[i]){
		ans = ans + " " + to_string(pre[i]);	
	}
	cout <<ans;
	
}
