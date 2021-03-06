//https://www.acmicpc.net/problem/11727
// BOJ 11727 2XN  2
#include <iostream>
#include <cstring>
#include <algorithm>

#define N_MAX 1001

using namespace std;

int dp[N_MAX];

int bottomUp(int n){
	for(int i =3 ;i<=n;i++){
		dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
	}
	return dp[n];
}
int topDown(int n){
	if(n == 0 || n == 1)
		return 1;
	if (dp[n]>0) //값 이미 찾은 경우 
		return dp[n]; 
		
	dp[n] = (topDown(n-1)+topDown(n-2)*2)%10007;	
	return dp[n];
}

int main(){
	int n;
	scanf("%d",&n);
	memset(dp,0 ,sizeof(int)*(n+1));
	fill_n(dp,n+1,0); //배열 초기 
	dp[1] = 1;
	dp[2] = 3;
	printf("%d",topDown(n));
	//	printf("%d",bottomUp(n));

	return 0;
	
}
