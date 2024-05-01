#include <bits/stdc++.h>

#define MAX_N 500001
using namespace std;

int arr[MAX_N];
int N, K;
int ans = 0;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int cnt = 0;
    int left = 0, right = 0;
    while (right < N) {

        if (arr[right] % 2) { //홀수

            if (cnt < K) cnt++;
            else {

                while (arr[left] % 2 == 0) //홀수 만날 때까지
                    left++;
                left++; //홀수 다음 위치부터   
            }
        }
        right++;
        // left ~ right-1 까지 수열 
        ans = max(ans, right - left - cnt);
    }
    cout << ans;
    return 0;
}
