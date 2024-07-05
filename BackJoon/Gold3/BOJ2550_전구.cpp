#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 10002
using namespace std;

int N;
int id[MAX_N], from[MAX_N], to[MAX_N], lis[MAX_N];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> id[i];
		from[id[i]] = i; // 시작 위치
	}
	for (int i = 1, a; i <= N; i++) {
		cin >> a;
		to[i] = from[a]; // a의 시작 위치
	}
	
	vector<int> rec, ans;
	for (int i(1),j; i <= N; i++) {
		j = lower_bound(rec.begin(), rec.end(), to[i]) - rec.begin();
		if (j == rec.size())rec.push_back(to[i]);
		else rec[j] = to[i];
		lis[i] = j;
	}
	for (int i(N), j = rec.size()-1; i; i--) {
		if (lis[i] == j) 
			ans.push_back(id[to[i]]), j--;
	}
	sort(ans.begin(), ans.end());
	cout << ans.size()<<"\n";
	for (int e : ans) cout << e << " ";
	
	return 0;
}
