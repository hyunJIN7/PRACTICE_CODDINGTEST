#include <unordered_map>
#include <vector>
#define MAX_N 10001
using namespace std;

unordered_map<int, int> idm;
struct node {
	int id, lat;
};
vector<vector<node>> network;
int total;

void init(int mD) {
	idm.clear();
	network.clear();
	network.reserve(MAX_N);
	idm.insert({mD,total++});
}

void connect(int oid, int nid, int mLatency) {
	idm.insert({ nid,total });
	nid = total++;
	network[oid].push_back({nid,mLatency});
	network[nid].push_back({ oid,mLatency });
}

int getLatency(int par,int from,int to,int lat) {
	if (from == to) return lat;

	for (node& n : network[from]) {

		if (n.id == par) continue;

		int ret = getLatency(from, n.id , to, lat + n.lat);
		if (ret) return ret;

	}
	return 0;

}

int measure(int id1, int id2) {
	id1 = idm[id1];
	id2 = idm[id2];
	getLatency(id1,id1,id2,0);
}

int getMaxLatency(int pid,int id) {

	int ret = 0;

	//내 하위에서 큰거 하나 뽑으며 올라간다.
	for (node& n : network[id]) {
		if (pid == n.id) continue;
		int lat = getMaxLatency(id,n.id) + n.lat;
		ret = max(ret, lat);
	}
	return ret;
}

int test(int id) {
	id = idm[id];

	int first = 0, second = 0;
	for (node& n : network[id]) {
		int lat = getMaxLatency(id, n.id) + n.lat;
		if (lat > first) {
			second = first;
			first = lat;
		}
		else if (lat > second) {
			second = lat;
		}
	}
	return first + second;
}
