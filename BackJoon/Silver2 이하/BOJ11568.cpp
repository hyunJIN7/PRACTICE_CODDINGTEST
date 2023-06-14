#include <bits/stdc++.h>
#define Fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 1001

using namespace std;
int N;
int card[MAX],dp[MAX]={0,};


int main(){
	Fastio;
	cin>>N;
	for(int i = 0 ; i < N ; i++) cin>>card[i];

	for(int i = 0 ; i < N ; i++){
		for(int j = i +1 ; j < N ; j++){
			
			if(card[i] < card[j]){
				dp[j] = (dp[j] < dp[i]+1 ) ?  dp[i]+1 : dp[j];
			}
			
		}
	}
	
	cout<< *max_element(dp,dp+N)  +1 ;
	
	//	int ans = 0;
//	for(int i = 0 ; i < N ; i++){
//		ans = (dp[i] < ans)? ans : dp[i];
//	}
//	cout<<ans+1<<endl;

}
