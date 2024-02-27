#include <vector>
#include <unordered_map>
#include <algorithm>
#include <bitset>
#include <cstring>
#define MAX_N 18005
using namespace std;

unordered_map<int, int> id_map;

int parent[MAX_N];
int sub[MAX_N]; // 하위 인원 수 본인 포함
int deg[MAX_N]; // 자식 수 
bitset<MAX_N> removed;
int group;
int total; // 총 부서 수 id 배분 때문에 

void init(int N, int mId[], int mNum[]) {
	memset(parent, 0, sizeof(parent));
	memset(sub, 0, sizeof(sub));
	memset(deg, 0, sizeof(deg));
	removed.reset();
	group = N;
	for (total = 1; total <= N; total++) {
		id_map[mId[total-1]] = total;
		sub[total] = mNum[total-1];
	}
	total = N;
	return;
}

int add(int id, int mNum, int pid) {
	pid = id_map[pid];
	if (deg[pid] >= 3) return -1;

	id = id_map[id] = ++total;
	removed.set(id, 0);
	parent[id] = pid;
	sub[id] = mNum;
	deg[id] = 0;
	deg[pid]++;

	int ret = sub[pid] + mNum;
	while (pid) {
		sub[pid] += mNum;
		pid = parent[pid];
	}
	return ret;
}

int remove(int id) {
	if (!id_map.count(id)) return -1;
	id = id_map[id];
	//위에 올라가며 pid 0으로 하면 안된다.
	for (int pid = id; pid; pid = parent[pid]) {
		if (removed.test(pid)) return -1;
	}
	int ret = sub[id];
	removed.set(id, 1);
	id = parent[id];
	deg[id]--;
	while (id) {
		sub[id] -= ret;
		id = parent[id];
	}
	return ret;
}

int distribute(int K) {
	int mx = 0;
	for (int i = 1; i <= group; i++)
		mx = max(mx, sub[i]);

	int l = 1,r = min(mx, K);
	while (l < r) {
		int m = (l + r + 1) / 2;
		int sum = 0;
		for (int i = 1; i <= group; i++) {
			sum += min(m, sub[i]);
		}
		if (sum <= K) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	return l;
}
