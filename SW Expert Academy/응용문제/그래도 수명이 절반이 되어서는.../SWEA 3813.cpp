#include<iostream>

using namespace std;

constexpr int MAX_N = 200000;

int N, K;
int wear[MAX_N], group[MAX_N];

bool place(const int max_level) {
	int cnt = 0; // group cnt 

	for (int i = 0; i < N; i++) {
		if (wear[i] > max_level) continue;

		int j = 0;
		for (; i + j < N && j < group[cnt]; j++) {
			if (wear[i + j] > max_level) {
				j++;
				break;
			}
			if (j >= group[cnt] - 1) {
				cnt++;
				if (cnt >=K) return true;
				j++;
				break;
			}
		}
		i += j - 1; //i++ 실행해서  
	}
	return false;
}

int solve() {
	int left = 1, right = MAX_N, ans = MAX_N;
	while (left < right) {
		int mid = (left + right) / 2;
		if (place(mid)) right = mid;
		else left = mid + 1;
	}
	return right;
}

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;
		for (int i = 0; i < N; i++) cin >> wear[i];
		for (int i = 0; i < K; i++) cin >> group[i];
		cout << "#" << test_case << " " << solve() << "\n";
	}
	return 0;
}
