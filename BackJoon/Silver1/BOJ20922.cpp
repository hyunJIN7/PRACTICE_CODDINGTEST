#include <iostream>
#define MAX_N 200000
#define MAX_A 100001
using namespace std;

int N, K;
int arr[MAX_N];
int cnt[MAX_A];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int ans = 1;
    int left = 0, right = 0;
    while (right < N) {
        int num = arr[right];
        if (cnt[num] < K) {
            cnt[num]++;
        }
        else {
            while (arr[left] != num) {
                cnt[arr[left]]--;
                left++;
            }
            left++; //right로 수가 대체됨.
        }
        right++;
        ans = max(ans, right - left);
    }
    cout << ans;
    return 0;
}
