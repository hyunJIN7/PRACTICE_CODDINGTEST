/*
관련 문제
https://www.acmicpc.net/problem/2293
https://www.acmicpc.net/problem/2437 
*/

#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include <string.h>
#include <vector>

using namespace std;

int T, N;
int score[100];
bool visited[10001] = { 0, };
vector<int> canScore;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(visited, 0, sizeof(visited));
        canScore.clear();
        canScore.push_back(0);
        visited[0] = true;

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> score[i];

            int size = canScore.size(); //미리 안빼면 계속 크기 바뀌니까.
            for (int j = 0; j < size; j++) {
                int newScore = canScore[j] + score[i];
                if (!visited[newScore]) {
                    visited[newScore] = true;
                    canScore.push_back(newScore);
                }
            }

        } 

        cout << "#" << t << " " << canScore.size() << "\n";
    }


    return 0;
}
