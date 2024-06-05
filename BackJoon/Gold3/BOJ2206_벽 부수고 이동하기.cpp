#include <bits/stdc++.h>

#define MAX_N 1000
#define MAX 987654321
using namespace std;

int N, M, K;
int grid[MAX_N][MAX_N];
bool vist[MAX_N][MAX_N][2];
int ans = MAX;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

struct node {
	int y, x, wall, dist;
};

bool InRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < M;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			grid[i][j] = s[j]-'0';
		}
	}

	vist[0][0][0] = true;
	queue<node> q;
	q.push({ 0,0,false,1 });
	while (!q.empty()) {
		node n = q.front(); q.pop();

		if (n.y == N - 1 && n.x == M - 1) {
			ans = min(ans, n.dist);
			continue;
		}

		for (int d = 0; d < 4; d++) {
			int ny = n.y + dy[d], nx = n.x + dx[d];
			if (!InRange(ny, nx) || vist[ny][nx][n.wall]) continue;		

			if (grid[ny][nx]) { // 벽
				if (n.wall) continue;
				q.push({ ny,nx,true,n.dist + 1 });
			}
			else { // 빈 곳
				q.push({ ny,nx,n.wall,n.dist + 1 });
			}
			vist[ny][nx][n.wall] = true;
		}
	}
	if (ans == MAX) ans = -1;
	cout << ans;
	
	return 0;
}
