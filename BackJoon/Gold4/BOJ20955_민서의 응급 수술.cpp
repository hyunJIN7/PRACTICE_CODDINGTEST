#include <iostream>
#include <vector>

#define MAX_N 100001
using namespace std;

int N;
int par[MAX_N];
int ans = 0;

int Parent(int a) {
	if (a == par[a]) return a;
	return par[a] = Parent(par[a]);
}

void Union(int a, int b) {
	a = Parent(a);
	b = Parent(b);
	if (a == b) {
		ans++;
		return;
	}
	par[b] = a;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) par[i] = i;

	while (M--) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	for (int i = 1; i <= N; i++) {
		if (i == Parent(i)) ans++;
	}
	cout << ans  - 1;

	return 0;
}
