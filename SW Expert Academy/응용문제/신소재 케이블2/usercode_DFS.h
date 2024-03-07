#include <unordered_map>
#include <vector>
#include <algorithm>
#define MAX_N 10002
using namespace std;
struct node {
	int id;
	int latency;
};
unordered_map <int, int> id_map; // 0부터 시작
vector<node> network[MAX_N];
int total;

void init(int mDevice)
{
	//각 network 100개씩 리사이즈 할까 
	for (int i = 0; i < MAX_N; i++) network[i].clear();
	id_map.clear();
	total = 0;
	id_map[mDevice] = total++;

}

int get_id(int id) { return id_map[id]; }

void connect(int mOldDevice, int mNewDevice, int mLatency)
{
	id_map[mNewDevice] = total;
	int from = get_id(mOldDevice);
	network[from].push_back({ total, mLatency });
	network[total].push_back({ from, mLatency });
	total++;
}

int getLatency(int par, int from, int to, int lat) {
	//일단 누적하며 끝까지 가고 대신 값은 to랑 같을 때만 리턴하면 됨.
	if (from == to) return lat;
	for (node& n : network[from]) {
		if (n.id != par) {
			int ret = getLatency(from, n.id, to, lat + n.latency);
			if (ret) return ret;
		}
	}
	return 0;
}

int measure(int mDevice1, int mDevice2)
{
	int id = get_id(mDevice1);
	return getLatency(id, id, get_id(mDevice2), 0);
}

int getMaxLatency(int par, int curr) {
	int max_lat = 0;
	for (node& n : network[curr]) {
		if (n.id != par) {
			int ret = getMaxLatency(curr, n.id) + n.latency;
			if (max_lat < ret)
				max_lat = ret;
		}
	}
	return max_lat;
}

// 어차피 connect에서 조건 때문에 사이클 안생겨
int test(int mDevice)
{
	int first = 0, second = 0;
	int id = get_id(mDevice);
	for (node& n : network[id]) {
		int latency = getMaxLatency(id, n.id) + n.latency;
		if (first < latency)
			second = first, first = latency;
		else if (second < latency)
			second = latency;
	}
	return first + second;
}
