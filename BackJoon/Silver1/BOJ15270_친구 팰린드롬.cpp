#include <bits/stdc++.h>
#define MAX_N 21

using namespace std;
typedef pair<int, int> pii;
int N, M;
vector<pii> vec;
bool used[MAX_N + 1] = { 0, };
int ans = 0;

// cnt 선택한 조합 수 
void solve(int idx, int cnt) {
	if (idx == M || cnt * 2 >= N) {
		ans = max(cnt, ans);
		return;
	}
	solve(idx + 1, cnt);
	int a, b;
	tie(a, b) = vec[idx];
	if (used[a] || used[b]) return;
	used[a] = used[b] = true;
	solve(idx + 1, cnt + 1);
	used[a] = used[b] = false;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back({ a,b });
	}

	solve(0,0);
	ans *= 2;
	if (N > ans) ans++;
	cout << ans;
	
}
