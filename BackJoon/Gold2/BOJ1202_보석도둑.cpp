#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int, int> pii;
int N, K;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;

	vector<pii> jewerly(N);
	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;
		jewerly[i] = { w,v };
	}
	vector<int> bag(K);
	for (int i = 0; i < K;) cin >> bag[i++];
	
	sort(jewerly.begin(), jewerly.end());
	sort(bag.begin(), bag.end());

	long long ans = 0;
	priority_queue<int> pq; 
	int idx = 0;
	for (int b : bag) {
		while (idx < N && jewerly[idx].first <= b) {
			pq.push(jewerly[idx].second);
			idx++;
		}
		
		while (!pq.empty()) {
			ans += pq.top(); pq.pop();
			break;
		}
	}
	cout << ans;

	return 0;
}
