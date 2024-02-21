#include <unordered_map>
#include <cstring>

#define MAX_N 8004
using namespace std;

unordered_map<int, int> id_map;

struct node {
	int par_id;//부모 id
	//vector<int> ch;
	int left_id;
	int right_id; // 왼오자식 idx
	int cnt; //해당 부서 인원
	int sum; //seg tree 하위 합 본인 그룹 포함
	node() : par_id(0), left_id(0), right_id(0), cnt(0), sum(0) {}

	// 복사 생성자
	node(const node& other) : par_id(other.par_id), left_id(other.left_id),
		right_id(other.right_id), cnt(other.cnt), sum(other.sum) {}
};

int total = 0;
bool created[MAX_N]; // 해당 id 노드 존재 여부
node tree[MAX_N];

int get_id(int id) {
	return id_map[id];
}

void create_node(int id, int pid, int cnt) {
	tree[id].par_id = pid;
	tree[id].left_id = 0;
	tree[id].right_id = 0;
	tree[id].cnt = cnt;
	tree[id].sum = cnt;
	created[id] = true;
}

void init(int mId, int mNum) {
	id_map.clear();
	total = 0;
	memset(created, 0, sizeof(created));

	id_map[mId] = ++total; //root =1
	create_node(1, 1, mNum);
	return;
}

void update(int node, int delta)
{   //bottom up
	//node : 업데이트 대상
	tree[node].sum += delta;
	if (node == 1) return;
	update(tree[node].par_id, delta);
}
int add(int mId, int mNum, int mParent) {
	int pid = get_id(mParent);
	if (tree[pid].left_id && tree[pid].right_id)
		return -1; // 자식 다 있는 경우
	id_map[mId] = ++total;
	create_node(total, pid, mNum);
	if (!tree[pid].left_id) { //왼쪽 자식으로
		tree[pid].left_id = total;
	}
	else { //오른쪽 자식으로 
		tree[pid].right_id = total;
	}
	update(pid, mNum);
	return tree[pid].sum;
}

void remove_node(int node) { //top down
	//초기화
	if (!node) return;
	if (tree[node].left_id)
		remove_node(tree[node].left_id);
	if (tree[node].right_id)
		remove_node(tree[node].right_id);
	created[node] = false;
}

int remove(int mId) {
	int id = get_id(mId);
	if (!created[id]) return -1;
	int pid = tree[id].par_id;
	int delta = tree[id].sum;
	if (tree[pid].left_id == id) tree[pid].left_id = 0;
	else tree[pid].right_id = 0;

	update(pid, -delta);
	remove_node(id); // remove를 할지 아님 그냥 false 만 할지 
	return delta;
}

int group_cnt = 0;
int query(int node, int M, int K)
{
	if (!created[node]) return 0;
	if (group_cnt > M || tree[node].cnt > K) {
		group_cnt = M + 1;
		return 0;
	}
	int left = query(tree[node].left_id, M, K);
	int right = query(tree[node].right_id, M, K);
	int sum = left + right + tree[node].cnt;
	if (group_cnt > M) return 0;
	if (sum <= K) {
		;
	}
	else if (sum - max(left, right) <= K) {
		group_cnt++;
		sum -= max(left, right);
	}
	else {
		group_cnt += 2;
		sum = tree[node].cnt;
	}
	if (node == 1 && sum) {
		group_cnt++;
		return 0;
	}
	return  sum;
}

int reorganize(int M, int K) {
	group_cnt = 0;
	query(1, M, K);
	return group_cnt <= M;
}
