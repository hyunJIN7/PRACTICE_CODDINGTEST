/*
현위치에서 보물 위치까지 휴리스틱한 거리 기준도 pq 정렬에 포함 시켜봤으나 큰 차이 없고 시간 길어짐. 
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#define MAX_N 501
using namespace std;
typedef tuple<int, int, int> tiii;

char grid[MAX_N][MAX_N];
vector<vector<int>> D(MAX_N, vector<int>(MAX_N, 2e9));

int H, W;
int ty, tx; // 보물 위치

priority_queue<tiii> pq;//연료 , y,x;

int dy[8] = { -1,-1,-1,0,1,1,1,0 };
int dx[8] = { -1,0,1,1,1,0,-1,-1 };

bool InRange(int y, int x) {
	return y && y <= H && x && x <= W;
}

//int getDis(int y, int x) { //보물까지 거리 
//	return max(abs(y - ty), abs(x - tx));
//}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'K') {
				D[i][j] = 0;
				pq.push({0,i,j});
			}	
			else if (grid[i][j] == '*')
				ty = i, tx = j;
		}
	}

	while (!pq.empty()) {
		auto [k, y, x](pq.top()); pq.pop();
		if (D[y][x] < (k*=-1)) 
			continue;

		for (int d = 0; d < 8; d++) {
			int ny = y + dy[d], nx = x + dx[d];
			if (InRange(ny, nx) && grid[ny][nx] ^ '#') {
				int nk = k + !(x < nx);
				if (nk < D[ny][nx]) {
					pq.push({ -(D[ny][nx] = nk),ny,nx });
				}
			}
		}
	}
	cout << (D[ty][tx] < 2e9 ? D[ty][tx] : -1);
	return 0;
}
