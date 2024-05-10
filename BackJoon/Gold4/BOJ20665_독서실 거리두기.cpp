#include <bits/stdc++.h>

#define MAX_N 101
#define MAX_P 500
using namespace std;

int N, T, P;
vector<pair<int, int>> qeury;
int seat[MAX_N];
int ans = 0;

int findMinSeatDist(int hour, int id) {
    // id의 자리와 가장 가까운 곳의 거리 
    // id 주변 자리 중 예약된 곳 중 가장 가까운 곳 
    int min_dist = MAX_N;
    for (int i = 1; i <= N; i++) {
        if (id == i) continue;
        if (hour < seat[i]) { //예약된 자리 
            int dist = abs(id - i);
            if (dist < min_dist)
                min_dist = dist;
        }
    }
    return min_dist;
}

int findSeat(int hour) {
    int ret = 0, max_dist = 0;
    for (int i = 1; i <= N; i++) {
        if (hour < seat[i])
            continue;//이미 누가 앉은 자리 
        int dist = findMinSeatDist(hour, i);
        if (max_dist < dist) {
            max_dist = dist;
            ret = i;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> T >> P;
    for (int i = 0; i < T; i++) {
        int s, e;
        cin >> s >> e;
        qeury.push_back({ s,e });
    }
    sort(qeury.begin(), qeury.end());

    ans = (21 - 9) * 60;
    for (pair<int, int> q : qeury) {
        int start, end;
        tie(start, end) = q;

        int id = findSeat(start);
        if (id == P) {
            ans += start / 100 * 60 + start % 100;
            ans -= seat[P] / 100 * 60 + seat[P] % 100;
        }
        seat[id] = end;  
    }
    //21시랑 비교
    ans -= seat[P] / 100 * 60 + seat[P] % 100;
    cout << ans;
    return 0;
}
