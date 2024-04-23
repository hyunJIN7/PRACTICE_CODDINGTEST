#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>

#define MAX_N 101
#define EMPTY '.'
#define MINERAL 'x'
using namespace std;
typedef pair<int, int> pii;

int H, W;
char grid[MAX_N][MAX_N];

bool vis[MAX_N][MAX_N];

vector<pii> vec;
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };


bool InRange(int y, int x) {
	return 1 <= y && y <= H && 1 <= x && x <= W;
}

bool CanGo(int y, int x) {
	return InRange(y, x) && grid[y][x] != EMPTY && !vis[y][x];
}

pii FindTarget(int h, bool left){
	if (left) {
		for (int i = 1; i <= W; i++) 
			if (grid[h][i] != EMPTY)
				return { h,i };
	}
	else {
		for (int i = W; i; i--)
			if (grid[h][i] != EMPTY)
				return{ h,i };
	}
	//없다면? 없을리가 있나 
	return { 0,0 };
}

void FindClustter(int y, int x) {
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d], nx = x + dx[d];
		if (CanGo(ny,nx)){
			vec.push_back({ ny,nx });
			vis[ny][nx] = true;
			FindClustter(ny, nx);
		}
	}
}

bool cmp(pii a, pii b) {
	return a.first > b.first;
}

bool CanMove(int h) {
	for (pii p : vec) {
		if (h + p.first > H ||
			grid[p.first + h][p.second] != EMPTY)
			return false;	
	}
	return true;
}

void Gravity() {
	//다 비워두고
	for (pii p : vec) {
		grid[p.first][p.second] = EMPTY;
	}

	int h = 1;
	while (1) {
		if(!CanMove(h)) break;
		h++;
	}
	h--; // h일 때 안되는거니가 

	for (pii p : vec) {
		grid[p.first + h][p.second] = MINERAL;
	}
}

void Simulate() {
	int t;
	cin >> t;
	bool left = false;
	while (t--) {
		int h;
		cin >> h;
		h = H + 1 - h;
		left ^= true;

		int y, x;
		tie(y,x) =  FindTarget(h, left);

		// 타켓 없으면 다음 턴 진행 
		if (make_pair(y,x) == make_pair(0, 0)) continue;
		grid[y][x] = EMPTY;
		memset(vis, 0, sizeof(vis));

		//위에 뭐 없음 
		vec.clear();
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d], nx = x + dx[d];
			if (CanGo(ny, nx)) {
				vec.push_back({ ny,nx });
				vis[ny][nx] = true;
				FindClustter(ny,nx);
				Gravity();
				vec.clear();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> H >> W;
	// 1~ N 까지!!! 
	for (int i = 1; i <= H; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= W; j++) {
			grid[i][j] = s[j - 1];
		}
	}

	Simulate();

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cout << grid[i][j];
		}
		cout << "\n";
	}
	return 0;
}
