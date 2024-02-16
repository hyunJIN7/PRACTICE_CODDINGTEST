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



/*
 // 덩어리들이 차지하는 블록의 최대 Wear Level이 mid이하를 만족하는 경우가 있는지 여부 리턴
bool isPossible(int x) {
	int k = 0; // 몇 번째 덩어리인지

	// 블록 순차탐색하면서
	for (int i = 0; i < N; i++) {
		// x를 넘으면 안됨
		if (arr[i] > x) continue;

		// 현재 덩어리의 끝 지점 (i부터 덩어리 크기 만큼)
		int end = i + brr[k];
		// 현재 덩어리를 i~end위치에 두었을 때, 덩어리가 차지하는 블록이 x이하를 만족하는지 체크
		for (int j = i; j < end && j < N; j++) {
			// x를 넘으면 안됨
			if (arr[j] > x)  {
				i = j;
				break;
			}

			// 현재 덩어리가 차지하는 블록이 x이하를 만족하는 경우
			if (j == end - 1) {
				i = j;
				k++;
			}
		}

		// 모든 덩어리에 대해 x이하인 블록을 차지할 수 있는 경우
		if (k == K) return true;
	}
	return false;

*/
