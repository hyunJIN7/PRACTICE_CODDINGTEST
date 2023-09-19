#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T = 10;
    freopen("input.txt", "r", stdin);
    for (int i = 1; i <= T; i++) {
        int N,ans=0;
        int buildings[1000];
        cin >> N;
        for(int i = 0; i < N; i++) cin >> buildings[i];



        for (int i = 2; i < N - 2; i++) {
            bool flag = true;

            int maxH = max(max(buildings[i - 1], buildings[i - 2]), max(buildings[i + 1], buildings[i + 2]));
            if (maxH< buildings[i]) ans+= buildings[i] - maxH;
        }

        cout << "#"<<i<<" "<< ans <<"\n";
    }


    return 0;
}
