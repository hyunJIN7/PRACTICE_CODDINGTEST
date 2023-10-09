#include <iostream>
#include <tuple>
#include <utility>

#define MAX_N 20
#define MAX_K 1000
#define DICE_FACE 6
#define DIR_NUM 4

using namespace std;

int N,M,K;
int y,x; // 주사위 위치 

int grid[MAX_N][MAX_N];
int movement[MAX_K];

int dice[DICE_FACE+1] = {0,}; // 주사위 면에 적힌 숫자 
int u = 1, f = 2, r = 3;//초기 상태 

int dy[DIR_NUM + 1] = {0, 0, 0, -1, 1};
int dx[DIR_NUM + 1] = {0, 1, -1, 0, 0};

bool InRange(int y, int x){
    return 0 <= y && y < N && 0 <= x && x < M;
}

void Simulate(int d){
    // 굴린 후에 복사해야함!! 
    int ny = y + dy[d], nx = x + dx[d];
    if(!InRange(ny,nx)) return;

    //위치 이동 
    y = ny;
    x = nx;

    //주사위 방향 바꾸기 
    if(d == 1){ // 동 
        tie(u, f, r) = make_tuple(7 - r, f, u);
    }
    else if(d == 2){ // 서 
        tie(u, f, r) = make_tuple(r, f, 7 - u);
    }
    else if(d == 3){  //북 
        tie(u, f, r) = make_tuple(f, 7 - u, r);
    } 
    else{  // 남 
        tie(u, f, r) = make_tuple(7 - f, u, r);
    }


    // 바닥 값 복사 
    int bottom = 7 - u;

    if(grid[y][x] == 0 ){  // 격자판 값 0
        grid[y][x] = dice[bottom]; // 바닥면 값 복사 
    }
    else{
        dice[bottom] = grid[y][x];
        grid[y][x] = 0;
    }

    cout<<dice[u]<<"\n";
}


void Input(){
    cin >> N >> M >> y >> x >> K;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0 ; i < K ; i++){
        cin>> movement[i];
        movement[i];
    }
}

void Solve(){
    Input();
    for(int i = 0 ; i < K ; i++){
        Simulate(movement[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
