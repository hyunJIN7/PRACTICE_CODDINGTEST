#include<iostream>
#include<cstring>

#define DIR_NUM 4
#define MAX 0x7f7f7f7f
using namespace std;

int dp[1000001][DIR_NUM];
int K;


int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dp, 0x7f, sizeof(dp));
	int energy[DIR_NUM];
	cin >> energy[3] >> energy[1] >> energy[2] >> K;

	for (int e = 1; e <= 3; e++) {
		int en = energy[e];
		dp[energy[e]][e] = 1;
	}
		

	for (int i = 1; i <= K; i++) {
		for (int d = 0; d < DIR_NUM; d++) {
			if (dp[i][d] == MAX) continue;

			for (int e = 1; e < DIR_NUM; e++) {
				int nxt_energy = i+ energy[e];
				int nxt_dir = (d + e) % DIR_NUM;
				if (nxt_energy <= K ) {
					dp[nxt_energy][nxt_dir] = min(dp[nxt_energy][nxt_dir],
						dp[i][d] + 1);
					int a = dp[nxt_energy][nxt_dir];
					int b = a;
				}
			}

		}
	}
	if (dp[K][0] == MAX)dp[K][0] = -1;
	cout << dp[K][0];
	return 0;
}
