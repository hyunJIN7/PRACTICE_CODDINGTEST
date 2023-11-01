#include <bits/stdc++.h>

#define MAX 5000
#define MOD 998244353

using namespace std;
typedef long long ll;

int N;
ll arr[MAX];
ll dp[MAX] = {0,};


int main(){
   ios::sync_with_stdio(false);cin.tie(0);
	cin >> N;
	for(int i = 0 ; i < N ; i++) cin >> arr[i];
	
	dp[0] = 1;
	dp[1] = (arr[0] < arr[1]) ? 2 : 1;
	
	for(int i = 2 ; i < N ; i++){
		dp[i]++;
		for(int j = i -1; j >=0 ; j--)
			if(arr[j] < arr[i]) dp[i] = (dp[i] + dp[j]) % MOD ;
	}
	
	for(int i = 0 ; i < N ; i++) cout << dp[i] << " ";
}
