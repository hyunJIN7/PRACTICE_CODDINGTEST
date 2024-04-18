#include <iostream>
#include <cstring>

#define MAX_N 1001
#define INF 0x7f7f7f7f
using namespace std;

int N;
int D[MAX_N][MAX_N], mD[MAX_N];
int A, B;

bool vis[MAX_N] = { 0, };
void dijkstra() {
    mD[A] = 0;
    for (int i = 0; i < N; i++) {
        int v = 1, dis = INF;

        //어차피 v=1부터 시작해서 
        for (int j = 2; j <= N; j++) {
            if (!vis[j] && mD[j] < dis) {
                v = j;
                dis = mD[j];
            }
        }
        vis[v] = true;
        for (int j = 1; j <= N; j++) {
            if (!vis[j] &&
                D[v][j] != INF &&
                mD[v] + D[v][j] < mD[j]) {
                mD[j] = mD[v] + D[v][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(D, 0x7f, sizeof(D));
    memset(mD, 0x7f, sizeof(mD));

    int M;
    cin >> N >> M;
    while (M--) {
        int f, t, d;
        cin >> f >> t >> d;
        D[f][t] = min(d, D[f][t]);
    }
    cin >> A >> B;
    dijkstra();
      
    cout << mD[B];

    return 0;
}
