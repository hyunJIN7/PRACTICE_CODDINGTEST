#include <bits/stdc++.h>

using namespace std;

int N;
int power[2001],dp[2001]={0,}; 

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0 ; i < N ; i++) cin>>power[i];
	
	int ans = 0;
	for(int i = N -1 ; i >= 0 ; i--){
		for(int j = i - 1; j>=0; j--){
			if(power[j] > power[i]){
				dp[j] = max(dp[j],dp[i]+1);	
			}		
		}
		ans = max(ans,dp[i]);
	}
	cout<<N-1-ans;
}
