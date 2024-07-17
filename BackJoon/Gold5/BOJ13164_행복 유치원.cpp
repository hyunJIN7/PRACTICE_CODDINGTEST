#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K;
	cin >> N >> K;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) cin >> vec[i];
	for (int i = 0; i < N - 1; i++) vec[i] = vec[i + 1] - vec[i];
	sort(vec.begin(), vec.end() - 1);

	int ans = 0;
	for (int i = 0; i < N - K; i++) ans += vec[i];
	cout << ans;
	return 0;
}
