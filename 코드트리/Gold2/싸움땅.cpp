#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_N 21
#define MAX_M 30
#define DIR_NUM 4

using namespace std;

int N,M,K;

vector<int> grid_gun[MAX_N][MAX_N];
int grid_player[MAX_N][MAX_N]={0,};


struct player{int y,x, dir, skill, gun;};
player player_info[MAX_M + 1];

int player_point[MAX_M + 1] = {0,}; 

int dy[DIR_NUM] = {-1, 0, 1, 0};
int dx[DIR_NUM] = {0, 1, 0, -1};

bool InRange(int y, int x){
    return 0 <= y && y< N && 0 <= x && x < N;
}

void SelectGun(int ny, int nx, int p){
    //ny, nx로 옮겨갈건데
    // 여기 총 중에 제일 좋은거 고르고 이동할거야
    //여기선 제일 총 고르기 

    // 정렬하고 고를까.... for문 한번만해도 가능하긴 한데..
    //가려는 곳 총 값 정렬
    sort(grid_gun[ny][nx].begin(), grid_gun[ny][nx].end() );

    //원래 가지고 있던 총 공격력 
    int origin_gun = player_info[p].gun;
    for(int i = grid_gun[ny][nx].size()-1; i >= 0 ; i--){
        // 혹시 여기 총 없을까봐, 없으면 실행 어차피 안하지만 혹시 모르니 
        int target_gun = grid_gun[ny][nx][ i ];
        if(origin_gun < target_gun){
            player_info[p].gun = target_gun;
            grid_gun[ny][nx].pop_back();
            if(origin_gun) grid_gun[ny][nx].push_back(origin_gun);
        }

        break;
    }
    //기존 코드 , 같은 내용이긴함 
    // int target_gun = grid_gun[ny][nx][grid_gun[ny][nx].size()-1];
    // if(origin_gun < target_gun){
    //     player_info[p].gun = target_gun;
    //     grid_gun[ny][nx].pop_back();
    //     if(origin_gun) grid_gun[ny][nx].push_back(origin_gun);
    // }
}

void Lose(int cy, int cx, int loser){
    //cy,cx 의 싸움에서 짐
    // 그 자리에 총 내려 놓고

    int loser_gun = player_info[loser].gun;
    player_info[loser].gun = 0;
    if(loser_gun) grid_gun[cy][cx].push_back(loser_gun);

    // cy,cx 이 위치 기준으로 근처로 이동 
    int loser_dir = player_info[loser].dir;
    for(int d = 0 ; d <= DIR_NUM; d++ ){ // 4 방향 돌며 빈 곳 찾기 
        int ny = cy + dy[ (loser_dir + d) % DIR_NUM ];
        int nx = cx + dx[ (loser_dir + d) % DIR_NUM ];
        if(InRange(ny,nx) && !grid_player[ny][nx]){ // 범위 안이고 사람 없으면 
            player_info[loser].dir = (loser_dir + d) % DIR_NUM ;
            grid_player[ny][nx] = loser;
            player_info[loser].y = ny;
            player_info[loser].x = nx;
            
            
            //옮겨간 자리에 총 있으면 찾기 
            SelectGun(ny,nx,loser);
            return;
        }
    }

}

// player 1과 player 2의 싸움
void Fight(int p1, int p2,int cy ,int cx){
    int power1 = player_info[p1].skill + player_info[p1].gun;
    int power2 = player_info[p2].skill + player_info[p2].gun;
    int point = abs(power1 - power2);
    int win = p1, lose = p2;

    if(power1 < power2){
        win = p2, lose = p1;
    }
    else if(power1 == power2){
        if(player_info[p1].skill < player_info[p2].skill){
            win = p2, lose = p1;
        }
    }

    //진 사람 처리!!
    //cy, cx에 대한 자리 싸움 이었음.

    // 총 내려 놓고, lose는 가던 길 계속 진행 
    // 사람 없는 곳으로 이동하며 (CW 90), 총 있으면 총 선택 
    Lose(cy, cx, lose);
    

    //이긴 사람은 여기 자리에 있고
    // 그 자리에 총 있으면 값 큰거 가지고 
    player_point[win] += point;
    grid_player[cy][cx] = win;
    player_info[win].y = cy;
    player_info[win].x = cx;
    SelectGun(cy, cx, win);


}

void Move(int ny, int nx, int py, int px, int p){
    //p 만 보내도 할 수 있긴 함. 
    player_info[p].y = ny;
    player_info[p].x = nx;
    grid_player[py][px] = 0;
    grid_player[ny][nx] = p;
}

void Simulate(){
    for(int p = 1 ; p <= M ; p++){
        //player의 현위치 
        int py = player_info[p].y , px = player_info[p].x;
        int dir = player_info[p].dir;

        // 이동할 위치 
        int ny = py + dy[dir], nx = px + dx[dir];
        // 범위 밖이면 정반대 방향으로 
        if(!InRange(ny,nx)){
            dir = (dir + 2) % DIR_NUM;
            player_info[p].dir = dir;
            ny = py + dy[dir], nx = px + dx[dir];
        }


        // 이동할 위치에 player가 있다면 
        if(grid_player[ny][nx]){  
            // 가기 전에 원래 위치에 일단 0 해줘야할지도 
            grid_player[py][px] = 0; // 왜냐 결과에 따라 ny,nx 기준으로 새롭게 옮기니까
            // 싸우는 플레이어 2명이랑 싸우는 위치  
            Fight(p, grid_player[ny][nx] , ny , nx); 
      
        }
        //이거 조건 작동 안할수도 있어서 확인해야해!!!!!!!!!!!
        else if (grid_gun[ny][nx].size() ){ // 이동할 위치에 총이 있다면
            SelectGun(ny,nx, p);
            Move(ny, nx, py, px, p);

        }
        else{
            //step 1. 방향만큼 한칸 이동
            Move(ny, nx, py, px, p);
        }

        

    }
}

void Init(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < N ; j++){
            grid_gun[i][j].clear();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Init();

    cin >> N >> M >> K;
    for(int i = 0 ; i < N; i++)
        for(int j = 0 ;j < N ; j++){
            int gun; cin >> gun;
            grid_gun[i][j].push_back(gun);
        }  
        
    for(int p = 1 ; p <= M ; p++){
        int y,x,d,s;
        cin >> y >> x >> d >> s;
        grid_player[y-1][x-1] = p;
        player_info[p] = player{y-1, x-1, d,s,0};
    }

    while(K--){
        Simulate();
    }

    for(int i = 1 ; i <= M ; i++)
        cout<<player_point[i]<<" ";

    return 0;
}
