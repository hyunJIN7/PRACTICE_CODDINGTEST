#include <bits/stdc++.h>

#define MAX_N 500001
using namespace std;

struct T {
    int s, e;
    bool operator<(const T& other) {
        if (s != other.s) return s < other.s;//s 오름차순
        return e < other.e;
    }
};
vector<T> vec;

struct cmp {
    bool operator()(const int& a, int& b) const {
        return a > b;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        vec.push_back({ s,e });
    }
    sort(vec.begin(), vec.end());

    int ans = 1;
    priority_queue<int, vector<int>, cmp> pq;
    pq.push(vec[0].e); // 끝나는 시간?..
    for (int i = 1; i < N; i++) {
        while (!pq.empty() && pq.top() <= vec[i].s) {
            pq.pop();
        }
        pq.push(vec[i].e);
        ans = max(ans, (int)pq.size());
    }
    cout << ans;
    return 0;
}
