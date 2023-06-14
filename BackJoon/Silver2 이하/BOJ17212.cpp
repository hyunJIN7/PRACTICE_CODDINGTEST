#include <bits/stdc++.h>
#define Fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


using namespace std;
int N;
int dp[100001]={0,1,1,2,2,1,2,1};

int Min(int a,int b,int c, int d){
	int min1 = (a<b)? a : b;
	int min2 = (c<d)? c : d;
	return (min1<min2)? min1 : min2;
}

int main(){
	Fastio;
	cin>>N;

	for(int i = 8; i <= N ; i++){
		dp[i] = Min(dp[i-1],	dp[i-2], dp[i-5], dp[i-7]) +1;
	}
	cout<<dp[N];
	
}
