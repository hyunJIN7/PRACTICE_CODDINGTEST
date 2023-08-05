#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int> vec;
int dp[41]={1,1,2,0};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	int left=1,right;
	for(int i = 0; i < M ; i++){
		cin>>right;
		vec.push_back(right-left);
		left = right + 1;
		
	}
	vec.push_back(N-left+1);
	
	
	for(int i = 3 ; i <= N ; i++){
		dp[i] = dp[i-2]+dp[i-1];
//		cout<<i<<"  :  "<<dp[i]<<endl;
	}
//	cout<<"##############\n";
	int ans = 1;
	for(auto e : vec){
		ans *= dp[e];
//		cout<<e<<" -> "<<ans<<endl;
	}
	cout<<ans;
	
}
