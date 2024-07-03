#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 301
using namespace std;

int N;
int grid[MAX_N][MAX_N];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	//1부터 시작해서 프리픽스구해서 최대값 구하자
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> grid[i][j];
			//prefix sum
			grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
		}
	}

	int ans = -987654321;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = min(i, j); k > 0; k--) {
				int sum = grid[i][j] - grid[i][j - k] - grid[i - k][j] + grid[i - k][j - k];
				ans = max(ans, sum);
			}

		}
	}
	cout << ans;

	return 0;
}
