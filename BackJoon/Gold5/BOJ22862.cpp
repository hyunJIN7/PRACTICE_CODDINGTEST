#include <iostream>
#define MAX_N 1000000
using namespace std;

int N, K;
int arr[MAX_N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 0;
    int cnt = 0;//홀수 개수 
    int left = 0, right = 0;
    while (right < N) {
        int num = arr[right];
        if (num % 2) {
            if (cnt >= K) {
                while (arr[left]%2 == 0) {
                    left++;
                }
                left++;
            }
            else cnt++;
        }
        right++;
        ans = max(ans, right - left - cnt);
    }
    cout << ans;
    return 0;
}
