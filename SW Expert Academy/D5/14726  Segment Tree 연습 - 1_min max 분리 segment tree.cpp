#include<iostream>
#include <cstring>
#include <climits>
#include <algorithm>

#define MAX_N 100001
using namespace std;

int N;
int arr[MAX_N];
int minTree[MAX_N * 4], maxTree[MAX_N * 4];

int initMin(int* tree, int node, int s, int e) {
	if (s == e) return tree[node] = arr[s];

	int m = (s + e) / 2;
	int left_value = initMin(tree, node * 2, s, m);
	int right_value = initMin(tree, node * 2 + 1, m + 1, e);
	return tree[node] = min(left_value, right_value);
}

int initMax(int* tree, int node, int s, int e) {
	if (s == e) return tree[node] = arr[s];

	int m = (s + e) / 2;
	int left_value = initMax(tree, node * 2, s, m);
	int right_value = initMax(tree, node * 2 + 1, m + 1, e);
	return tree[node] = max(left_value, right_value);
}

int minQuery(int* tree, int node, int ts, int te, int qs, int qe) {
	if (qs <= ts && te <= qe) return tree[node];
	if (te < qs || qe < ts) return INT_MAX;

	//일부 겹친 경우  
	int m = (ts + te) / 2;
	int left_value = minQuery(tree, node * 2, ts, m, qs, qe);
	int right_value = minQuery(tree, node * 2 + 1, m + 1, te, qs, qe);
	return min(left_value, right_value);
}

int maxQuery(int* tree, int node, int ts, int te, int qs, int qe) {
	if (qs <= ts && te <= qe) return tree[node];
	if (te < qs || qe < ts) return -1;

	int m = (ts + te) / 2;
	int left_value = maxQuery(tree, node * 2, ts, m, qs, qe);
	int right_value = maxQuery(tree, node * 2 + 1, m + 1, te, qs, qe);

	return max(left_value, right_value);
}

int updateMin(int* tree, int node, int s, int e, int ii, int val) {
	if (ii < s || e < ii) return tree[node]; //min 값 비교해줘야하니  
	if (s == e) return tree[node] = val;

	int m = (s + e) / 2;
	int left_value = updateMin(tree, node * 2, s, m, ii, val);
	int right_value = updateMin(tree, node * 2 + 1, m + 1, e, ii, val);
	return tree[node] = min(left_value, right_value);
}

int updateMax(int* tree, int node, int s, int e, int ii, int val) {
	if (ii < s || e < ii) return tree[node]; //min 값 비교해줘야하니  
	if (s == e) return tree[node] = val;

	int m = (s + e) / 2;
	int left_value = updateMax(tree, node * 2, s, m, ii, val);
	int right_value = updateMax(tree, node * 2 + 1, m + 1, e, ii, val);
	return tree[node] = max(left_value, right_value);
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
		fill(minTree, minTree + N * 4, INT_MAX);
		memset(maxTree, 0, sizeof(maxTree));
		for (int i = 1; i <= N; i++) cin >> arr[i];

		initMin(minTree, 1, 1, N); // segtree init
		initMax(maxTree, 1, 1, N);
		cout << "#" << test_case << " ";
		while (Q--) {
			int op, l, r;
			cin >> op >> l >> r;

			if (op) { //1번쿼리  
				cout << maxQuery(maxTree, 1, 1, N, l + 1, r) - minQuery(minTree, 1, 1, N, l + 1, r) << " ";
			}
			else { // 0번 퀄;  
				updateMin(minTree, 1, 1, N, l + 1, r);
				updateMax(maxTree, 1, 1, N, l + 1, r);
			}

		}
		cout << "\n";
	}
	return 0;
}
