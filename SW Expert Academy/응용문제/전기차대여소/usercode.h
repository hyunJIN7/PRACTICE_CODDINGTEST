#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>

#define MAX_N 350
#define WALL -2
#define EMPTY -1
#define DIR_NUM 4
using namespace std;
typedef pair<int, int> pii;

int range;
int N, cnt;//cnt는 station 수 

int grid[MAX_N][MAX_N];
vector<pii> station[200]; // id, 거리

void init(int n, int mRange, int mMap[MAX_N][MAX_N])
{
	N = n;
	range = mRange;

	for (int i = 0; i < cnt; i++) station[i].clear();
	// 빈곳 -1, 벽 -2
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			grid[i][j] = (mMap[i][j]) ? WALL : EMPTY;
		}
	}
}

bool inRange(int y, int x){
	return 0 <= y && y < N && 0 <= x && x < N;
}

int dy[DIR_NUM] = { 0,0,1,-1 }, dx[DIR_NUM] = { 1,-1,0,0 };
bool visited[MAX_N][MAX_N];
void add(int mId, int mRow, int mCol)
{
	memset(visited, 0, sizeof(visited));
	cnt = mId + 1;

	queue<pii> q;
	visited[mRow][mCol] = true;
	q.push({mRow,mCol}); //위치 
	for (int dist = 0; dist <= range; dist++) {
		for (int size = q.size(); size; --size) {
			int y, x;
			tie(y, x) = q.front(); q.pop();

			if (grid[y][x] >= 0) {
				int other = grid[y][x];
				station[mId].push_back({ other, dist });
				station[other].push_back({ mId, dist });
			}
			for (int i = 0; i < DIR_NUM; i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if (!inRange(ny, nx) || visited[ny][nx]) continue;
				if (grid[ny][nx] == WALL) continue; //벽이면 못가
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
	grid[mRow][mCol] = mId;
}


struct Node {
	int d,id;
	const bool operator < (const Node& other) const {
		return d > other.d;//pq의 내림차순
	}
};

int dist[200];
int distance(int mFrom, int mTo)
{
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<Node> pq; //거리,id
	pq.push({ 0,mFrom });
	dist[mFrom] = 0;

	while (!pq.empty()) {
		Node c = pq.top(); pq.pop();

		if (dist[c.id] < c.d) continue; // 값 갱신됨.
		if (c.id == mTo)	return c.d;

		for (pii ns : station[c.id]) {
			//id,거리
			int new_dis = c.d + ns.second;
			if (new_dis < dist[ns.first]) {
				dist[ns.first] = new_dis;
				pq.push({ new_dis, ns.first });
			}
		}
	}
	return -1;
}
