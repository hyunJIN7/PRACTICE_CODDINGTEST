#include <bits/stdc++.h>

#define MAX_M 1000
using namespace std;
typedef long long ll;

int N, M;
ll mod[MAX_M];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;

    ll psum = 0;
    while (N--) {
        int num; cin >> num;
        psum = (psum + num) % M;
        mod[psum]++;
    }
    ll ans = mod[0];
    for (int i = 0; i < M; i++) {
        ans += mod[i] * (mod[i] - 1) / 2;
    }
    cout << ans;

    return 0;
}
