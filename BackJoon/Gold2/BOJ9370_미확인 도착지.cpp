#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 0x7f7f7f7f
#define MAX_N 2001
using namespace std;

int N;
int S, G, H;
int dist[MAX_N][MAX_N], mdist[MAX_N], mdist_g[MAX_N], mdist_h[MAX_N];
bool vis[MAX_N];
void dijkstra(int start, int *d) {
	memset(vis, 0, sizeof(vis));
	d[start] = 0;
	for (int i = 1; i <= N; i++) {
		int v = 1, md = INF;
		for (int j = 1; j <= N; j++) {
			if (!vis[j] && d[j] < md) {
				v = j;
				md = d[j];
			}
		}
		vis[v] = true;
		for (int j = 1; j <= N; j++) {
			if (!vis[j] && dist[v][j] != INF) {
				d[j] = min(d[j],d[v] + dist[v][j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int TC;
	cin >> TC;
	while (TC--) {
		int M, T;
		cin >> N >> M >> T >> S >> G >> H;
		memset(dist, 0x7f, sizeof(dist));
		memset(mdist, 0x7f, sizeof(mdist));
		memset(mdist_g, 0x7f, sizeof(mdist_g));
		memset(mdist_h, 0x7f, sizeof(mdist_h));

		while(M--) {
			int a, b, d;
			cin >> a >> b >> d;
			dist[a][b] = d;
			dist[b][a] = d;
		}

		dijkstra(S, mdist);
		dijkstra(G, mdist_g);
		dijkstra(H, mdist_h);
		vector<int> vec;
		while (T--) {
			int to;
			cin >> to;
			if (mdist[to] == mdist[G] + dist[G][H] + mdist_h[to] ||
				mdist[to] == mdist[H] + dist[G][H] + mdist_g[to])
				vec.push_back(to);
		}
		sort(vec.begin(), vec.end());
		for (int e : vec)
			cout << e << " ";
		cout << "\n";
	}
	return 0;
}
