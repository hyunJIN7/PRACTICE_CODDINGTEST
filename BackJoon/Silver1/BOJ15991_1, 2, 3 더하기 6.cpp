#include <iostream>
#include <cstring>

#define MOD 1000000009
#define MAX_N 100001

using namespace std;

int N;
int dp[MAX_N] = { 0,1,2,4, }; // 1,2,3으로 N을 표현할 수 있는 개수(대칭 생각 안하고)

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TC;
	cin >> TC;

	for (int i = 4; i <= MAX_N / 2; i++) {
		dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3])% MOD;
	}

	int arr[4] = { 0,1,2,2 };
	while (TC--) {
		cin >> N;
		if (N <= 3) {
			cout << arr[N] << "\n";
			continue;
		}
		if (N % 2) { // 홀수
			cout << (dp[(N - 1) / 2] + dp[(N - 3 )/ 2])% MOD << "\n";
		}
		else cout << (dp[N / 2] + dp[(N - 2) / 2]) % MOD <<"\n";
	}
	return 0;
}
