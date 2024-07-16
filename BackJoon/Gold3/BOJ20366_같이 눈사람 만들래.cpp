#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int N;
vector<ll> vec;
ll ans = 2e9;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N;) cin >> vec[i++];
	sort(vec.begin(), vec.end());

	for (int i = 0; i < N - 3; i++) {
		for (int j = i + 3; j < N; j++) {
			int left = i + 1, right = j - 1;
			ll sum1 = vec[i] + vec[j];
			while (left < right) {
				ll sum2 = vec[left] + vec[right];
				ans = min(ans, abs(sum1 - sum2));
				if (sum2 == sum1) break;
				if (sum2 < sum1) left++;
				else right--;
			}
		}
	}
	cout << ans;
	return 0;
}
