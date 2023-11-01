#include <bits/stdc++.h>

#define MOD 1000000009
#define MAX 100001

using namespace std;
typedef long long ll;

ll dp[MAX][4] = {0,};

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
	
	for(int i = 4 ; i < MAX ; i++){
		dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
		dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
		dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
	}
	int n;
	cin >> n;
	while(n--){
		int num; 
		cin >> num;
		cout << (dp[num][1] + dp[num][2] + dp[num][3])% MOD << "\n";
	}
		
}
