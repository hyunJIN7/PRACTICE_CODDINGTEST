#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int road[100][100];
int accuT[100][100];//누적시간

void BFS() {
    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    queue<pair<int, int>> que;
    que.push({ 0,0 });
    while (!que.empty()) {
        int y = que.front().first, x = que.front().second;
        que.pop();
  
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if (accuT[ny][nx] > accuT[y][x] + road[ny][nx]){
                accuT[ny][nx] = accuT[y][x] + road[ny][nx];
                que.push({ ny,nx });
            }
        }
    }

}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            string input;
            cin >> input;
            
            for (int j = 0; j < N; j++) {
                road[i][j]=input[j]-'0';
                accuT[i][j] = 999999;
            }
        }
        accuT[0][0] = 0;
        BFS();
        cout << "#" << i << " " << accuT[N-1][N-1] << "\n";

    }


    return 0;
}
