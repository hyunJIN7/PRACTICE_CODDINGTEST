#include <iostream>
#include <cstring>
#include <cmath>
#define MAX_N 5001
using namespace std;
int N, K;
int e[MAX_N], dp[MAX_N];

// top - down
// 도달 가능 여부만 확인하면 된다
// 갈 수 있으면 바로 끝 
// 2중 for 사용 가능

int canGo(int target) {
    int& ret = dp[target];
    if (ret != -1) return ret;

    ret = 0; //0으로 설정, 일단 못간다 세팅  
    // i -> target으로 이동 
    for (int i = 0; i < target; i++) {
        int power = (target - i) * (1 + abs(e[target] - e[i]));
        if (power <= K) {
            if (canGo(i)) {
                return ret = 1; // 1
            }
        }
    }
    return ret; // 0
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> e[i];

    memset(dp, -1, sizeof(dp)); //-1 : 아직 안봤다.
    dp[0] = 1; // 갈 수 있다.
    cout << (canGo(N-1) ? "YES" : "NO");
    return 0;
}
