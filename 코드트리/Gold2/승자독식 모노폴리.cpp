#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define DIR_NUM 4
#define MAX_N 20
#define MAX_M 400
#define MAX_K 1000
#define EMPTY 0

using namespace std;

int N,M,K;

int grid_player[MAX_N][MAX_N] = {0,};//사용자 위치 
vector<int> new_grid_player[MAX_N][MAX_N];
 

pair<int,int> grid_room[MAX_N][MAX_N] ; //각 방 주인과 독점 기간 

// pair<int,int> player_pos[MAX_M + 1]; // 각 플레이어 현 위치, END 때문에 남김    
int player_dir[MAX_M + 1]; // 플레이어 이동 방향, 즉 직전에 이동한 방향
int dir_priority[MAX_M + 1][DIR_NUM][DIR_NUM]; // 사용자별 현방향에 따른 우선순위 
int dy[DIR_NUM] = {-1,1,0,0}; // 북남서동
int dx[DIR_NUM] = {0,0,-1,1};

int ans = -1;

bool InRange(int y,int x){
    return 0 <= y && y < N && 0 <= x && x < N;
}

bool End(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(grid_player[i][j] > 1) return false; 
        }
    }
    return true;
}

void Renewal(int y,int x){
    // cout<<y<<" "<<x <<endl;

    //new_grid에 여려멍 있는 경우나 한명 이상 있는 경우
    sort(new_grid_player[y][x].begin(),new_grid_player[y][x].end());
    for(int i = 0 ; i < 1 ; i++){
        grid_player[y][x] = new_grid_player[y][x][i];
        grid_room[y][x] = make_pair(new_grid_player[y][x][i], K+1);
    }
}

void Move(int py,int px,int player){
    // 현재 내 방향의 우선순위에 따라 주변 칸 탐색
    int pd = player_dir[player];
    for(int i = 0; i < DIR_NUM; i++){
        int nd = dir_priority[player][pd][i];
        int ny = py + dy[nd], nx = px + dx[nd];
        if(InRange(ny,nx) && grid_room[ny][nx].first == EMPTY){
            //범위내, 방 독점 없으면 
            new_grid_player[ny][nx].push_back(player);
            grid_player[py][px] = 0;// 원래 위치에서 지워주고 
            player_dir[player] = nd;

            return; // 
        }

    }

    //4 방향 중 다 독점계약 되어 있다면 
    for(int i = 0; i < DIR_NUM; i++){
        int nd = dir_priority[player][pd][i];
        int ny = py + dy[nd], nx = px + dx[nd];
        if(InRange(ny,nx) && grid_room[ny][nx].first == player){
            //범위내, 내 독점 방이면
            new_grid_player[ny][nx].push_back(player);
            grid_player[py][px] = 0;// 원래 위치에서 지워주고
            player_dir[player] = nd;
            return; 
        }
    }

}

void Init(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            new_grid_player[i][j].clear();
        }
    }

}

void Simulate(){
    Init();
    //방 독점 감소 아래에 두고 다 k+1로 해줄까?
     for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            int player,period;
            tie(player,period) = grid_room[i][j];
            period--;
            if(period <= 0) player = period = 0;
            grid_room[i][j] = make_pair(player,period);

        }
    }


    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(grid_player[i][j]){
                Move(i,j,grid_player[i][j]);
            }
        }
    }

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
        // 이제 new_grid에 있는 플레이어 정리해줘야지.
        // 독점계약 갱신하고 여러명 있으면 낮은 것만 남기고      
            if(new_grid_player[i][j].size() != EMPTY)       
                Renewal(i,j);
        }
    }


}

void Input(){
    cin >> N >> M >> K;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> grid_player[i][j];
            if(grid_player[i][j]){
                //방 계약 
                grid_room[i][j] = make_pair(grid_player[i][j],K+1);
            }
        }
    }
    for(int p = 1; p <= M; p++){
        int d; cin >> d;
        player_dir[p] = d - 1; // 0부터 방향 시작이라 
    }
    //방향 우선순위 인풋
    for(int p = 1; p <= M; p++){
        for(int d1 = 0; d1 < DIR_NUM; d1++){
            for(int d2 = 0; d2 < DIR_NUM; d2++){
                int d; cin >> d;
                dir_priority[p][d1][d2] = d - 1; 
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    Input();
    for(int i = 1; i <= MAX_K; i++){
        
        Simulate();
        if(End()){
            ans = i; 
            break;
        }
    }
    cout<< ans;
    


    return 0;
}
