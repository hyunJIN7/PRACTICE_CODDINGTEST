#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#define MAX_N 501
using namespace std;
typedef tuple<int, int, int> tiii;

int N, K;
vector<tiii> bus[MAX_N];//목적지,가는 시간, 대기 시간 
vector<vector<int>> dist(MAX_N, vector<int>(MAX_N, 2e9));
priority_queue<tiii> pq; //누적거리,목적지, k

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int M;
	cin >> N >> M >> K;
	while (M--) {
		int s, e, t, g;
		cin >> s >> e >> t >> g;
		bus[s].emplace_back(e, t, g);
	}

	for (pq.push({ dist[1][0] = 0,1,0 }); !pq.empty();) {
		auto [cost, s, k](pq.top()); pq.pop();

		if (dist[s][k] < (cost *= -1)) continue;

		for (auto [nxt, t, g] : bus[s]) {
			int next_cost = cost + t;
			if (cost % g) {
				if (k < K && next_cost < dist[nxt][k + 1])
					pq.push({ -(dist[nxt][k + 1] = next_cost),nxt,k + 1 });

				next_cost = (cost / g + 1) * g + t;
				if (next_cost < dist[nxt][k])
					pq.push({ -(dist[nxt][k] = next_cost),nxt,k });
			}
			else { // 대기 시간으로 나누어 떨어짐.
				if (next_cost < dist[nxt][k]) 
					pq.push({ -(dist[nxt][k] = next_cost) , nxt,k});
			}

		}
	}
	int ans = *min_element(dist[N].begin(), dist[N].end());
	cout << (ans == 2e9 ? -1 : ans);
	return 0;
}

