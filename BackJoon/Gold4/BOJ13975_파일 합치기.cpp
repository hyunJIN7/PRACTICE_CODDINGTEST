#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#define MAX_N 100004
using namespace std;
typedef long long ll;
  
int N;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> N;
		
		while (N--) {
			ll c;
			cin >> c;
			pq.push(c);
		}

		ll ans = 0;
		while (pq.size() > 1) {
			ll tmp = pq.top();
			pq.pop();
			tmp += pq.top();
			pq.pop();
			ans += tmp;
			pq.push(tmp);
		}
		pq.pop();
		cout << ans << "\n";
	}
	return 0;

}
