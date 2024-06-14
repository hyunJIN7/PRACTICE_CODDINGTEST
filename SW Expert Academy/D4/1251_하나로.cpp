#include<iostream>
#include <vector>
#include <iomanip>
 
using namespace std;
typedef long long ll;
 
void solve() {
    int N;
    cin >> N;
    vector<int> y(N), x(N);
    //for (int i = 0; i < N; i++) cin >> y[i];
    //for (int i = 0; i < N; i++) cin >> x[i];
    for (int& it : y) cin >> it;
    for (int& it : x) cin >> it;
    double E;
    cin >> E;
 
    auto getDist = [&](int i, int j)-> ll {
        return 1LL * (y[i] - y[j]) * (y[i] - y[j]) +
            1LL * (x[i] - x[j]) * (x[i] - x[j]);
    };
 
    vector<ll> dist(N, (ll)1e18 + 7);
    vector<bool> vis(N);
 
    vis[0] = true;
    dist[0] = 0;
 
    long long ans = 0;
    int cid = 0;
    for (int i = 0; i < N - 1; i++) { //N-1개 선 찾기
        ll min_dist = 1e18 + 7;
        int nid = 0;
        for (int j = 0; j < N; j++) {
            if (vis[j]) continue;
 
            // 이걸로해야 기존에 연결된 것과 제일 가까운 거 찾기
            dist[j] = min(dist[j], getDist(cid, j));
            if (dist[j] < min_dist ) {
                nid = j;
                min_dist = dist[j];
            }
        }
        vis[nid] = true;
        cid = nid;
        ans += dist[nid];
    }
    cout << fixed << setprecision(0) << E * ans << "\n";
}
 
int main(int argc, char** argv)
{
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        cout << "#" << test_case << " ";
        solve();
    }
 
    return 0;
}
