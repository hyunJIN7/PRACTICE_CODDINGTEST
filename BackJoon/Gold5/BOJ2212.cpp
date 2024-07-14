#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K ,ans = 0;
	cin >> N >> K;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());

	//사이 간격만 보면 된다. 그리고
	// 최대 K개 라곤 하지만 K개 그룹 만들어야 영역 최소 된다.
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	N = vec.size();
	for (int i = 0; i < N-1; i++) vec[i] = vec[i + 1] - vec[i]; // 간격
	
	vec.pop_back();
	sort(vec.begin(), vec.end());

	for (int i = 0; i < N - K; i++) ans += vec[i];
	cout << ans;
	return 0;
}
