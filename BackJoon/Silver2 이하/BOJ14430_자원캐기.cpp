#include <iostream>
#define MAX_N 300

using namespace std;

int N, M;
int grid[MAX_N][MAX_N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> grid[i][j];

	for (int i = 1; i < N; i++)
		grid[i][0] += grid[i - 1][0];
	for (int i = 1; i < M; i++)
		grid[0][i] += grid[0][i - 1];

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
		}
	}
	cout << grid[N-1][M-1];

	return 0;
}
