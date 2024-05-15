#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
#include <cmath>

#define MAX_N 100
using namespace std;

int N;
vector<pair<double, double>> pos;

int par[MAX_N];

struct edge { double dist; int a, b; };
struct cmp {
    bool operator()(const edge& a, const edge& b){
        return a.dist > b.dist;
    }
};
priority_queue<edge, vector<edge>, cmp > pq;

double ans = 0;

int Parent(int a) {
    if (par[a] == a) return a;
    return par[a] = Parent(par[a]);
}

void Union(int a, int b) {
    a = Parent(a);
    b = Parent(b);

    par[b] = a;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        double y, x; cin >> y >> x;
        pos.push_back({ y,x });
        par[i] = i;
    }

    //가중치 구하기 
    for (int i = 0; i < N; i++) {
        double y1, x1;
        tie(y1, x1) = pos[i];
        for (int j = i+1 ; j < N; j++) {
            double y2, x2;
            tie(y2, x2) = pos[j];
            pq.push({ sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1)),
                i,j });
        }
    }

    //N-1 개 간선 구하기 
    for (int i = 0; i < N - 1; i++) {
        edge e = pq.top(); pq.pop();

        int pa = Parent(e.a), pb = Parent(e.b);
        if (pa == pb) {
            i--; continue;
        }
        ans += e.dist;
        Union(e.a, e.b);
    }
    cout << ans;
    return 0;
}
