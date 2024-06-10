#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>

#define MAX_N 10
using namespace std;

int N;
vector<int> tree[MAX_N][MAX_N];

int grid[MAX_N][MAX_N], a[MAX_N][MAX_N];

int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };

vector<pair<int, int>> mother_pos;

bool InRange(int y, int x) {
	return 0 <= y && y < N && 0 <= x && x < N;
}

void Grow(int y, int x) {
	// 성장, 죽음 처리
	int cnt = -1;
	vector<int>& t = tree[y][x];
	for (int i = 0; i < (int)t.size(); i++) {
		if (grid[y][x] < t[i]) {
			cnt = t.size() - i;
			break;
		}
		grid[y][x] -= t[i];
		t[i]++;
		if (!(t[i] % 5))
			mother_pos.push_back({ y,x });
	}

	if (cnt == -1) return;

	while (cnt--) {
		grid[y][x] += t.back() / 2;
		t.pop_back();
	}
}

void Reverse() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			reverse(tree[i][j].begin(), tree[i][j].end());
		}
	}
}

void Breed() {
	Reverse();
	for (pair<int, int> p : mother_pos) {
		for (int d = 0; d < 8; d++) {
			int ny = p.first + dy[d], nx = p.second + dx[d];
			if (InRange(ny, nx)) 
				tree[ny][nx].push_back(1);
		}
	}

	Reverse();
	mother_pos.clear();
}

void Supply() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			grid[i][j] += a[i][j];
		}
	}
}

void Simulate() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Grow(i, j);
	Breed();
	Supply();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			grid[i][j] = 5;
		}
	while (M--) {
		int y, x, z;
		cin >> y >> x >> z;
		tree[y - 1][x - 1].push_back(z);
	}

	while (K--)
		Simulate();

	int ans = 0;//살아남은 나무 수 체크 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans += tree[i][j].size();
	cout << ans;
	return 0;
}
