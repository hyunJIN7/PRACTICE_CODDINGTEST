#include <bits/stdc++.h>

#define INF 1000001
#define MAX_N  10001
using namespace std;
typedef pair<int, int> pii;

int N;
vector<pii> edge[MAX_N];
bool vis[MAX_N];

struct cmp {
    bool operator()(const pii& a, const pii& b) const {
        return a.second > b.second;
    }
};


int getMinDis() {
    // MST Prim
    int ret = 0;

    // 첫번째 정점 택 
    int curr = 1;
    priority_queue<pii,vector<pii>,cmp> pq;
    for (int i = 0; i < N - 1; i++) {
        // N-1 개 엣지 탐색
        vis[curr] = true; //여긴 가면 안됨 이제 
        // 그동안 방문한 정점들과 연결된 엣지 중
        for (pii p : edge[curr]) {
            if (vis[p.first]) continue; // 방문 했다면 패스
            pq.push(p);
        }

        // 가장 가까운 곳 탐색 방문 안했고 
        while (!pq.empty()) {
            pii n = pq.top();
            if (!vis[n.first]) {
                curr = n.first;
                ret += n.second;
                break;
            }
            pq.pop();
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M;
    cin >> N >> M;
    
    while (M--) {
        int a, b, d;
        cin >> a >> b >> d;
        edge[a].push_back({ b,d });
        edge[b].push_back({ a,d });
    }
    cout << getMinDis();

    return 0;
}
