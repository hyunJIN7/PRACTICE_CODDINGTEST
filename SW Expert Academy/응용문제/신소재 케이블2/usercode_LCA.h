#include <unordered_map>
#include <vector>
#include <cstring>
#define MAX_N 10004
using namespace std;

int parent[MAX_N];
int depth[MAX_N];
int latency[MAX_N]; //바로 직전 부모와의 latency
unordered_map<int, int> idm;
int total;

int firstId[MAX_N], secondId[MAX_N];
int firstLat[MAX_N], secondLat[MAX_N];

void init(int mDevice)
{
	memset(depth, 0, sizeof(depth));
	memset(latency, 0, sizeof(latency));
	memset(firstId,0,sizeof(firstId));
	memset(secondId,0,sizeof(secondId));
	memset(firstLat, 0, sizeof(firstLat));
	memset(secondLat, 0, sizeof(secondLat));
	idm.clear();

	total = 1;
	idm[mDevice] = total++;
}


void update(int pid, int cid) {

	for (int lat = 0; pid ; ) {
		lat += latency[cid];
		
		if (cid == firstId[pid]) {

			if (firstLat[pid] < lat) {
				firstLat[pid] = lat;
			}
			else break;
		}
		else if (firstLat[pid] < lat) {
			secondLat[pid] = firstLat[pid];
			secondId[pid] = firstId[pid];

			firstLat[pid] = lat;
			firstId[pid] = cid;
		}
		else if (secondLat[pid] < lat) {
			secondLat[pid] = lat;
			secondId[pid] = cid;
		}
		else break;

		cid = pid, pid = parent[pid];
	}

}

void connect(int oid, int nid, int mLatency)
{
	oid = idm[oid];
	nid = idm[nid] = total++;

	parent[nid] = oid;
	depth[nid] = depth[oid] + 1;
	latency[nid] = mLatency;
	
	update(oid, nid);
}


int measure(int id1, int id2)
{
	id1 = idm[id1];
	id2 = idm[id2];
	if (depth[id1] > depth[id2]) swap(id1, id2);
	int diff = depth[id2] - depth[id1];
	int ret = 0;
	while(diff--){
		ret += latency[id2];
		id2 = parent[id2];
	}

	while (id1 != id2) {
		ret += latency[id1] + latency[id2];
		id1 = parent[id1];
		id2 = parent[id2];
	}
	return ret;
}

int test(int id)
{
	id = idm[id];
	int ret = firstLat[id] + secondLat[id];

	int pid = parent[id];
	int lat = firstLat[id];

	while (pid) {
		lat += latency[id]; //id에서 pid까지 가는  

		if (secondId[pid]) { 
			// 부모 노드의 자식이 2개 이상이라면
			// pid에서 다른 노드로 가는 거리 더해서 비교 
			if (firstId[pid] == id) {
				ret = max(ret, lat + secondLat[pid]);
			}
			else {
				ret = max(ret, lat + firstLat[pid]);
			}
		}
		else ret = max(ret, lat); // 자식 1개라면 바로 비교 
		
		id = pid;
		pid = parent[pid];
	}
	return ret;
}
