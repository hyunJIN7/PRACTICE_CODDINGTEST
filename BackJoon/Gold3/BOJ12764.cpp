#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<pii> people;
struct room { int e, id; };
struct cmp {
	bool operator()(const room& a, const room& b) {
		if (a.e == b.e) return a.id > b.id;
		return a.e > b.e;
	}
};
priority_queue<room, vector<room>, cmp> use; 
priority_queue<int, vector<int>, greater<int>> wait;
int ans = 0;
int cnt[100004];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	people.reserve(N);
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		people.push_back({ s,e });
	}
	sort(people.begin(), people.end());

	for (int i = 0; i < N; i++) {
		int s, e;
		tie(s, e) = people[i];
		
		while (!use.empty() && use.top().e <= s ) {
			wait.push(use.top().id);
			use.pop();
		}

		int id = ans;
		if (wait.empty()) ans++;
		else {
			id = wait.top();
			wait.pop();
		}
		use.push({ e,id });
		cnt[id]++;
	}
	cout << ans <<"\n";
	for (int i = 0; i < ans; i++) cout << cnt[i] << " ";

	return 0;
}
