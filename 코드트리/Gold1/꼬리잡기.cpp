#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>

#define MAX_N 20
#define MAX_M 5
#define DIR_NUM 4

using namespace std;

int N,M,K;

int grid[MAX_N][MAX_N];
vector<pair<int,int> > group[MAX_M + 1]; // 1~5번 그룹 존재

bool visited[MAX_N][MAX_N] = {0,};

int dy[DIR_NUM] = {0,-1,0,1};
int dx[DIR_NUM] = {1,0,-1,0};


int total_score = 0;

bool InRange(int y , int x){
    return 0 <= y && y< N && 0 <= x && x < N;
}

void Move(int g){
    int sy,sx, ey,ex; // 그룹 시작,끝 위치 
    tie(sy,sx) = group[g][0];
    tie(ey,ex) = group[g][group[g].size()-1];
    // cout<< g<<": "<<sy<<" "<<sx<<", "<<ey<<" , "<<ex<<endl;


    //첫번째 위치는 꼬리랑 닿을 수 도 있어서 따로 해줄거야 .
    //머리 제외하고 옮겨주기 
    for(int i = group[g].size()-1;  i > 0; i--){
        int ny,nx;
        tie(ny,nx) = group[g][i-1];//옮길 위치, 즉 내 앞차례
        group[g][i] = make_pair(ny,nx);    
        // tie(cy,cx) = group[g][i];// 옮길 대상
    }

    // 머리 옮기기 
    // 맨앞과 맨뒤만 값 바꿔주면 됨 grid 
    grid[ey][ex] = MAX_M + 1;//꼬리값은 앞으로 땡겨지면 6이니까 미리 바꿔 
    for(int d = 0 ; d < DIR_NUM; d++){
        int ny = sy + dy[d], nx = sx + dx[d];
        if(InRange(ny,nx) && grid[ny][nx] == MAX_M + 1){
            //범위 안에 있으면서 6(이동궤적)이면 가
            group[g][0] = make_pair(ny,nx);
            grid[ny][nx] = g;
            break;
        }
    }


}

pair<int,int> TrowBall(int dir, int y, int x){
    pair<int,int> change_target = make_pair(-1,-1);
    int ny = y, nx = x;
    for(int i = 0 ; i < N ; i++){
        if( 1 <= grid[ny][nx] && grid[ny][nx] <= M ){
            change_target = make_pair(ny,nx);
            break;
        }
        ny = (ny + dy[dir] + N) % N;
        nx = (nx + dx[dir] + N) % N;
    }
    return change_target;
}

void Simulate(int round){
    // 이동
    for(int g = 1 ; g <= M ; g++){
        Move(g);
    }

    //공 던지기
    int ball_dir = (round % (4*N)) / N;
    int ball_sy, ball_sx;//공 던지기 시작 위치 
    if(ball_dir == 0){
        ball_sy =  round % N;
        ball_sx = 0;
    }
    else if(ball_dir == 1){
        ball_sy = N-1;
        ball_sx = round % N;
    }
    else if(ball_dir == 2){
        ball_sy = N-1-round % N;
        ball_sx = N-1;
    }
    else if(ball_dir == 3){
        ball_sy = 0;
        ball_sx = N-1-round % N;
    }
    // cout<<round<<" : "<< ball_dir <<" "<<ball_sy<<" "<<ball_sx<<endl;
    // //공 만나는 그룹 번호 반환 
    pair<int,int> change_target = TrowBall(ball_dir, ball_sy, ball_sx);
    if(change_target == make_pair(-1,-1)) return;
    // cout<<"공 맞음 "<<change_target.first<<" "<<change_target.second<<endl;
    int change_group = grid[change_target.first][change_target.second];
    for(int i = 0 ; i < group[change_group].size(); i++){
        if(change_target == group[change_group][i]){
            total_score += (i+1)*(i+1);
            break;
        }
    }

    // change_group 머리 꼬리 바꾸기 
    reverse(group[change_group].begin(),group[change_group].end());



}


void FindGroup(int y, int x , int g){
    
    queue<pair<int,int> > q;
    q.push({y,x});
    visited[y][x] = true;
    grid[y][x] = g;

    int tail_y=-1,tail_x=-1;

    while(!q.empty()){
        int cy, cx;
        tie(cy, cx) = q.front();
        
        q.pop();
        // cout<<cy<<" "<< cx << endl;
        for(int d = 0 ; d < DIR_NUM; d++){
            int ny = cy + dy[d], nx = cx + dx[d];
            if(!InRange(ny,nx) || visited[ny][nx]) continue;
            if(grid[ny][nx] == 2){
                // 하나의 동선에 한팀만 있다니까 해본다.
                
                q.push({ny,nx});
                visited[ny][nx] = true;
                group[g].push_back({ny,nx});
                grid[ny][nx] = g;// 

            }
            else if (grid[ny][nx] == 3){
                tail_y=ny, tail_x= nx;
                visited[ny][nx] = true;
            }
        }

    }

    if(make_pair(tail_y,tail_x) != make_pair(-1,-1)){
        group[g].push_back({tail_y,tail_x});
        grid[tail_y][tail_x] = g;
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // Input
    cin>> N >> M >> K;
    for(int i = 0, g = 1 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1){
                group[g].push_back({i,j});
                g++;
            }
            else if(grid[i][j] == 4)
                grid[i][j] = MAX_M + 1; //6으로 만들기
            
        }
    }

    // 그룹 별로 만들기
    memset(visited,false,sizeof(visited));
    for(int g = 1 ; g <= M; g++){
        int sy,sx;
        // 각 그룹의 머리
        tie(sy,sx) = group[g][0];
        FindGroup(sy,sx,g);
        // cout<<g<<" : "<<group[g].size()<<endl;
    }

    //필요한 값들 초기화
    //벡터도 클리어해주고 다해줘야해. 

    for(int i = 0 ; i < K ; i++){
        Simulate(i);
    }

    cout<< total_score;
    // for(int i = 0 ; i < N ; i++){
    //     for(int j = 0 ; j < N ; j++){
    //         cout<< grid[i][j] << " ";
            
            
    //     }
    //     cout<<endl;
    // }


     

    return 0;
}
