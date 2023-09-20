#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include <string.h>
#include <vector>
#define MAX 100

using namespace std;

int T=10, N;
int ans = 0;
int map[MAX][MAX] = { 0, };
int endX;

int dy[3] = { 0,0,-1 };
int dx[3] = { -1,1,0 };
int visited[MAX][MAX] = {0, };

void DFS(int y, int x) {
   
    if (y == 0) {
        ans = x;
        return;
    }

    //cout << y << "  " << x << endl;

    for (int i = 0; i < 3; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (nx < 0 || nx >= MAX || !map[ny][nx] || visited[ny][nx]) continue;
        visited[ny][nx] = true;
        DFS(ny,nx);
        break;
    }


}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.txt", "r", stdin);


    for (int t = 1; t <= T; t++) {
        memset(visited, 0, sizeof(visited));

        cin >> N;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                cin >> map[i][j];
                if (map[i][j] == 2) endX = j;
            }
        }
        visited[MAX-1][endX] = true;
        DFS(MAX - 1, endX);
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}
