#include <vector>
#define RATE 256
using namespace std;

vector<vector<int> > type;
vector<int> edgeTime, edgeType;
vector<int> segTree;

int init(vector<int> &tree, int node, int s,int e) {
	if (s == e) return tree[node] = edgeTime[s];

	int m = (s + e) / 2;
	int left_value = init(tree, node * 2, s, m);
	int right_value = init(tree, node * 2 + 1, m + 1, e);
	return tree[node] = left_value + right_value;
}

void init(int N, int M, int mType[], int mTime[])
{
	edgeTime.resize(N-1);
	edgeType.resize(N-1);
	type.resize(M);
	segTree.resize(4 * (N-1));
	for (int i = 0; i < N-1; i++) {
		type[mType[i]].push_back(i); // edge i는 mType[i] 타입
		edgeType[i] = mType[i];
		edgeTime[i] = mTime[i];
	}

	init(segTree, 1 , 0 , N-2); // 0~N-2 번 edge 의 통과 시간
}

void destroy()
{
	type.clear();
	edgeTime.clear();
	edgeType.clear();
	segTree.clear();
}

int update(vector<int>& tree, int node, int s, int e, int ii, int delta) {
	if (ii < s || e < ii) return tree[node];
	tree[node] += delta;
	if (s == e) return tree[node];
	int m = (s + e) / 2;
	return update(tree, node * 2, s, m, ii, delta) + update(tree, node * 2 + 1, m + 1, e, ii, delta);
}

void update(int mID, int mNewTime)
{
	update(segTree, 1, 1, edgeTime.size(), mID + 1, mNewTime - edgeTime[mID]);
	edgeTime[mID] = mNewTime;
}

int updateByType(int mTypeID, int mRatio256)
{
	int sum = 0;
	for (int e : type[mTypeID]) {
		int newTime = edgeTime[e] * mRatio256 / RATE;
		sum += newTime;
		update(e, newTime);
	}
	return sum;
}

int query(vector<int>& tree, int node, int ts, int te, int qs,int qe) {
	if (qe < ts || te < qs) return 0;
	if (qs <= ts && te <= qe) return tree[node];

	int m = (ts + te) / 2;
	int left_val = query(tree, node * 2, ts , m , qs, qe);
	int right_val = query(tree, node * 2 + 1, m+1, te, qs, qe);
	return left_val + right_val;
}

int calculate(int mA, int mB)
{
	return query(segTree, 1 , 1 , edgeTime.size(),min(mA,mB)+1, max(mA,mB));
}
