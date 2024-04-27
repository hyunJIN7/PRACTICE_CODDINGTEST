#include <iostream>
#include <queue>
#define MAX_N 1000001

using namespace std;
typedef long long ll;

int N;
ll dp[MAX_N]; //N번째 감소하는 수 저장

void dfs() {
	int cnt = 1;

	queue<ll> q;
	for (int i = 1; i <= 9; i++) q.push(i);
	while (!q.empty() && cnt <= N) {
		ll curr = q.front(); q.pop();
		dp[cnt++] = curr;
		for (int i = 0; i < curr % 10; i++) {
			q.push(curr * 10 + i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	dfs();
	if (dp[N] || N == 0) cout << dp[N];
	else cout << -1;
	return 0;
}
