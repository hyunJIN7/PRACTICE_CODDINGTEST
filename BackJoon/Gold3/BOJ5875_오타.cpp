#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;
    int ans = 0;

    int sum = 0;
    int left = 0, right = 0;

    for (char c : str) {
        if (c == '(') {
            sum++; left++;
        }
        else if (c == ')') {
            sum--; right++;
        }

        if (sum <= 1) //위반되는 조건의 위치만 생각 
            left = 0;
        if (sum == -1) {
            ans = right;
            break;
            //유효하지 않은 순간 발생
            //유효하지 않은 곳은 한 곳이니 아기 앞부분을 고쳐야한다.
        }      
    }
    if (sum > 0) ans = left; 
    //개수 위반되는 (
    // 위반 되는 조건은 1초과인 순간 
    cout << ans;
}
