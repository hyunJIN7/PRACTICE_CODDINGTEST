#include <unordered_map>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int cityCnt = 0;
unordered_map<int, int> m; //실제 번호, 새로운 번호(1~600) 
vector<vector<pair<int, int> > > edge, back_edge;

int init(int N, int sCity[], int eCity[], int mCost[]) {
	edge.clear();
	back_edge.clear();
	m.clear();
	cityCnt = 0;

	for (int i = 0; i < N; i++) {
		// 새로운 도시 번호 부여
		if (!m[sCity[i]]) m[sCity[i]] = ++cityCnt;
		if (!m[eCity[i]]) m[eCity[i]] = ++cityCnt;
	}
	edge.resize( cityCnt + 1 );
	back_edge.resize( cityCnt + 1 );
	for (int i = 0; i < N; i++) {
		edge[m[sCity[i]]].push_back({ m[eCity[i]] , mCost[i] });
		back_edge[m[eCity[i]]].push_back({ m[sCity[i]] , mCost[i] });
	}
	return cityCnt;
}

void add(int sCity, int eCity, int mCost) {
	edge[m[sCity]].push_back({ m[eCity] , mCost });
	back_edge[m[eCity]].push_back({ m[sCity] , mCost });
	return;
}

int getMinSum(int start, const vector<vector< pair<int, int> > > &vec) {
	vector<int> total(cityCnt + 1, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
	total[start] = 0;
	pq.push({ 0, start});
	while (!pq.empty()) {
		//auto [curr_cost, curr_city] = pq.top();
		int curr_cost, curr_city;
		tie(curr_cost, curr_city) = pq.top();
		pq.pop();
		if (total[curr_city] < curr_cost) continue;
		for (const pair<int, int> e : vec[curr_city]) {
			if (curr_cost + e.second < total[e.first]) {
				total[e.first] = curr_cost + e.second;
				pq.push({ curr_cost + e.second, e.first });
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= cityCnt;) sum += total[i++];
	return sum;
}

int cost(int mHub) {
	mHub = m[mHub];
	return getMinSum(mHub, edge) + getMinSum(mHub, back_edge);
}
