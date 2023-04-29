#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll DIV=1000000007;
ll dp[1005][1005]={0,};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int H,W;
	cin>>H>>W;

	
	for(int i = 0 ; i < H ; i++)dp[i][0]=1;
	for(int i = 0 ; i < W ; i++)dp[0][i]=1;
	
	for(int i=1 ; i < H ; i++){
		for(int j=1; j < W ; j++){
			dp[i][j] = ( dp[i-1][j-1]  + dp[i][j-1] +dp[i-1][j])%DIV  ;  

		}
			
	}
	
	cout<<dp[H-1][W-1];
}
