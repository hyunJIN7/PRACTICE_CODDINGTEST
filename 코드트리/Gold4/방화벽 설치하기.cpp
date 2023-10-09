#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

#define MAX 8
#define FIRE_NUM 2
#define FIREWALL_NUM 1
#define BLANK_NUM 0
#define ADDITIONAL_FIREWALL 3
#define DIR_NUM 4

using namespace std;

int N,M;
int map[MAX][MAX];
vector<pair<int,int> > blank_pos;

int max_area = 0;
int fireball[ADDITIONAL_FIREWALL][2];

bool visited[MAX][MAX] = {0,};
bool fire[MAX][MAX] = {0,};//불퍼졌을때 어디에 새로 퍼지는지 확인 

int dy[DIR_NUM] = {0, 0, 1, -1};
int dx[DIR_NUM] = {1, -1, 0, 0};

bool InRange(int y, int x){
    return 0 <= y && y < N && 0 <= x && x < M;
}

bool CanGo(int y, int x){
    return InRange(y,x) && !visited[y][x] && !map[y][x];
    //빈칸이면서 범위 안이고 방문 안한 곳 
}

void DFS(int y,int x){
    visited[y][x] = true;
    fire[y][x] = true;

    for(int i = 0 ; i < DIR_NUM ; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(CanGo(ny,nx)){
            //빈칸이고 방문 안했고 
            DFS(ny,nx);
        }
    }
}

int GetMaxArea(){ // 현재 상태에서 fire 퍼트리기  
    //불퍼트리기
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < M ; j++){
            if(map[i][j] == FIRE_NUM && !visited[i][j]){
                //불이고 방문 안한 곳 
                DFS(i,j);
            }
        }
    }

    // 불 퍼진거에서 빈칸 개수 찾기 
    // fire와  map 보면서 불 아니고 벽 아니고 빈칸인곳 
    int ans = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < M ; j++){
            if( !fire[i][j] && map[i][j] == BLANK_NUM ){
                ans++;
            }
        }
    }    
    return ans;
}

void SearchFireWall(int cnt,int start){
    //빈칸 중 방화벽 설치할 위치 백트래킹으로 찾기
    if(cnt == ADDITIONAL_FIREWALL){
        memset(visited, false, sizeof(visited) );
        memset(fire, false, sizeof(fire) );
        max_area = max(max_area, GetMaxArea());
        return;
    }

    for(int i = start; i < blank_pos.size(); i++ ){
        int y,x;
        tie(y,x) = blank_pos[i];
        fireball[cnt][0] = y;
        fireball[cnt][1] = x;
        map[y][x] = FIREWALL_NUM;

        SearchFireWall(cnt+1, i+1);

        map[y][x] = BLANK_NUM;
    }
}

void Input(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < M ; j++){
            cin >> map[i][j];
            if(map[i][j] == BLANK_NUM) blank_pos.push_back({i,j});
        }
    }
}

void Solve(){
    Input();
    SearchFireWall(0,0);
    cout<<max_area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
