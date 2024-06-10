#include <iostream>
#include <cstring>
#include <climits>

#define MAX_N 5005
using namespace std;
typedef long long ll;

int N;
ll a[MAX_N], dp[MAX_N] = { 0, };


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	
	for (int i = 1; i < N; i++) {
		dp[i] = LONG_MAX;
		for (int j = 0; j < i; j++) {
			ll power = (i - j) * (1 + abs(a[i] - a[j]));
			dp[i] = min(dp[i], max(dp[j], power));
			// j에서 i 까지 오는 중에는 최대값을 찾아야하고
			// i 값 중에선 min이어야하고
		}
	}
	cout << dp[N-1];
	return 0;
}
