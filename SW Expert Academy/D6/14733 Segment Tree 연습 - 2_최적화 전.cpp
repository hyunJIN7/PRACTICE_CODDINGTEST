#include<iostream>
#include <cstring>
#include <climits>

#define MAX_N 100001
using namespace std;

int N;
int oddArr[MAX_N], evenArr[MAX_N];
long long oddTree[MAX_N * 4], evenTree[MAX_N * 4];

long long init(long long* tree, int* arr, int node, int s, int e) {
	if (s == e) return tree[node] = arr[s];

	int m = (s + e) / 2;
	long long left_val = init(tree, arr, node * 2, s, m);
	long long right_val = init(tree, arr, node * 2 + 1, m + 1, e);
	return tree[node] = left_val + right_val;
}

long long query(long long* tree, int node, int ts, int te, int qs, int qe) {
	if (qs <= ts && te <= qe) return tree[node];
	if (te < qs || qe < ts) return 0;

	int m = (ts + te) / 2;
	long long left_val = query(tree, node * 2, ts, m, qs, qe);
	long long right_val = query(tree, node * 2 + 1, m + 1, te, qs, qe);
	return left_val + right_val;
}

long long update(long long* tree, int node, int s, int e, int ii, int val) {
	if (ii < s || e < ii) return tree[node]; //업데이트 할거 없이 반환
	if (s == e) return tree[node] = val;

	int m = (s + e) / 2;
	long long left_val = update(tree, node * 2, s, m, ii, val);
	long long right_val = update(tree, node * 2 + 1, m + 1, e, ii, val);
	return tree[node] = left_val + right_val;
}


int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;

	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int Q;
		cin >> N >> Q;
		memset(oddTree, 0, sizeof(oddTree));
		memset(evenTree, 0, sizeof(evenTree));
		for (int i = 1; i <= N; i++) {
			if (i % 2) cin >> oddArr[i];
			else cin >> evenArr[i];
		}

		init(oddTree, oddArr, 1, 1, N);
		oddTree;
		init(evenTree, evenArr, 1, 1, N);
		evenTree;
		cout << "#" << test_case << " ";
		while (Q--) {
			int op, l, r;
			cin >> op >> l >> r;

			if (op) { //1번쿼리  
				if ((l + 1) % 2)
					cout << query(oddTree, 1, 1, N, l + 1, r) - query(evenTree, 1, 1, N, l + 1, r) << " ";
				else
					cout << query(evenTree, 1, 1, N, l + 1, r) - query(oddTree, 1, 1, N, l + 1, r) << " ";
			}
			else { // 0번 퀄;  
				if ((l + 1) % 2) update(oddTree, 1, 1, N, l + 1, r);
				else update(evenTree, 1, 1, N, l + 1, r);
			}
		}
		cout << "\n";
	}
	return 0;
}
