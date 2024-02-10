#include<iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <tuple>
#include <queue>

#define MAX_N 50000
using namespace std;

vector<pair<int, int> > onward[MAX_N], backward[MAX_N];
int N, X;
int total_time[MAX_N];
 
void solve(vector<pair<int, int>> vec[MAX_N]) {
	int min_time[MAX_N];
	fill(min_time, min_time + N, INT_MAX);
	queue<int> q;
	q.push(X);
	min_time[X] = 0;
	while(!q.empty()) {
		int curr_node = q.front();
		q.pop();
		for (pair<int, int> e : vec[curr_node]) {
			if (min_time[curr_node] + e.second < min_time[e.first]) {
				min_time[e.first] = min_time[curr_node] + e.second;
				q.push(e.first);
			}
		}
	}
	for (int i = 0; i < N; i++) total_time[i] += min_time[i];
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int M;
		cin >> N >> M >> X;
		
		memset(total_time, 0, sizeof(total_time));
		for (int i = 0; i < N; i++) {
			onward[i].clear();
			backward[i].clear();
		}
		
		while (M--) {
			int s, e, t;
			cin >> s >> e >> t;
			onward[--s].push_back({ --e,t });
			backward[e].push_back({ s,t });
		}
		
		--X;
		solve(onward);
		solve(backward);
		int ans = 0;
		for (int i = 0; i < N; i++) ans = max(ans, total_time[i]);
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}
