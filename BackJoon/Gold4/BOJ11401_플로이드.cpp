#include <iostream>
#include <queue>
#include <cstring>

#define MAX_N 101
#define INF 0x3f3f3f3f
using namespace std;
int N;
int grid[MAX_N][MAX_N];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			grid[i][j] = ((i == j) ? 0 : INF);

	while (M--) {
		int s, e, w;
		cin >> s >> e >> w;
		grid[s][e] = min(grid[s][e], w);
	}

	for (int k = 1; k <= N; k++) 
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++) 
				grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << ((grid[i][j] == INF) ? 0 : grid[i][j]) << " ";
		}
		cout << "\n";
	}
	return 0; 
}
