/*
  보통의 BFS,DFS 처럼 현재 칸만 고려하는 것이 아닌 이제까지 확정된 칸의 주변 칸을 탐색하며 나아가는 방법 
*/
#include <iostream>
#include <vector>
#include <tuple>

#define MAX 200
#define BLOCKSIZE 4
#define DIR_NUM 4

using namespace std;

int N,M;
int map[MAX][MAX];

int ans = 0; 

int dy[DIR_NUM] = {0, 0, -1, 1};
int dx[DIR_NUM] = {-1, 1, 0, 0};

vector<pair<int,int> > visited;
 
bool InRange(int y, int x){
    return 0 <= y && y < N && 0 <= x && x < M;
}

bool CanGo(int y, int x){
    if(!InRange(y,x)) return false;

    pair<int,int> pos = {y,x};
    for(int i = 0 ; i < visited.size(); i++){
        if(visited[i] == pos) return false;
    }
    return true;
 
}


void SearchMaxBlock(int cnt, int sum){
    if(cnt == BLOCKSIZE){
        ans = max(ans,sum);
        return;
    }

    //지금까지 방문한 위치들의 인접 위치 이동 가능 여부 확인 
    // 지금 현재 cnt  위치에 있는 블록 하나만 보는 것이 아닌
    // 이때까지 방문한(4개까지 가능한 그거) 것들의 주변을 살펴보는 과정 
    for(int i = 0 ; i < visited.size(); i++){
        int y,x;
        tie(y,x) = visited[i];

        for(int d = 0 ; d < DIR_NUM; d++){
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(CanGo(ny,nx)){
                visited.push_back({ny,nx});
                SearchMaxBlock(cnt + 1, sum + map[ny][nx]);
                visited.pop_back();
            }
        }

    }
}


void Input(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < M ; j++){
            cin >> map[i][j];
        }
    }
}


void Solve(){
    Input();

    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < M ; j++){
            visited.push_back({i, j});
            SearchMaxBlock(1, map[i][j]);
            visited.pop_back();
        }
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}
