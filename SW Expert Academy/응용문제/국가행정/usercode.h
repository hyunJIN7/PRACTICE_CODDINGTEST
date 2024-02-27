#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int* population;
int bridgeCnt[10000];

struct Bridge {
	int t,id;
	//TODO : pq는 정렬 방법이 다르네....vector에서 이렇게 하면 오름차순인데
	// pq는 내림 차순되네...
	bool operator < (const Bridge &other)  const {
		if (t != other.t) return t < other.t;
		return id > other.id;
	}
};
priority_queue<Bridge> pq;
int seg[1 << 15];//구간 합
int base;
int N;

void init(int n, int mPopulation[])
{
	memset(seg, 0, sizeof(seg));
	pq = priority_queue<Bridge>();
	population = mPopulation;
	N = n;

	for (base = 1; base < n-1;) { base <<= 1;}

	for (int i = 0; i < N - 1; i++) {
		int t = mPopulation[i] + mPopulation[i + 1];
		seg[base + i] = t;
		pq.push({ t , i });
		bridgeCnt[i] = 1;
	}

	for (int i = base - 1; i ; i--) {
		seg[i] = seg[i * 2] + seg[i * 2 + 1];
	}
}

void seg_update(int id, int delta) { //base부터 올라간다.
	seg[id+=base] += delta;
	while (id >>= 1) seg[id] += delta;
}

int expand(int M)
{
	int ret = 0;
	while (M--) {
		Bridge b = pq.top();
		pq.pop();
		
		ret = (population[b.id] + population[b.id + 1] ) / (++bridgeCnt[b.id]);

		pq.push({ ret, b.id });
		//seg_update(b.id, ret );
		seg_update(b.id, ret - b.t);
	}
	return ret;
}

int seg_query(int qs, int qe) {
	int ret = 0;
	qs += base;
	qe += base;
	while (qs <= qe) {
		if (qs % 2 == 1) ret += seg[qs++];
		if (qe % 2 == 0) ret += seg[qe--];
		qs >>= 1;
		qe >>= 1;
	}
	return ret;
}


int calculate(int mFrom, int mTo)
{
	if (mTo < mFrom) swap(mFrom, mTo);
	return seg_query(mFrom,mTo-1);
}


int divide(int mFrom, int mTo, int K)
{
	int left =  1, right = 10'000'000;
	while (left < right) {
		int mid = (left + right) / 2;

		int group_cnt = 0;

		for (int i = mFrom; i <= mTo; group_cnt++) {
			int j = i;
			int sum = 0;
			while (j <= mTo &&  sum + population[j] < mid) {
				sum += population[j++];
			}
			i = j;
		}
		// 가장 많은 인구의 선거구 인구를 최소로 한다.
		if (group_cnt <= K) { // 최소를 최대로 
			right = mid;
		}
		else {
			left = mid + 1;	
		}
	}
	return right;
}
