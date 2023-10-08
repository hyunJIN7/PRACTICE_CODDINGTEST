// x ,y 로 진행함. 
#include <iostream>
#include <cstring>

#define MAX_N 20
#define GRID_MAX 100
#define DIR_NUM 4

using namespace std;

int N;

//현재 세대 커브를 이루는 점 위치
bool curr_point[GRID_MAX+1][GRID_MAX+1];
//현재 세대에서 새롭게 그려지는 점 
bool new_point[GRID_MAX+1][GRID_MAX+1];
//최종 커브 점
bool paper[GRID_MAX+1][GRID_MAX+1];

struct point{int x,y;};
point Roate(int x, int y, int center_x, int center_y){
    //센터 기준 CW 90' 회전 
    return point{ y - center_y +  center_x, center_x - x + center_y };
}

void InitCurCurve(){
    memset(curr_point,false,sizeof(curr_point));
}
void InitNewCurve(){
    memset(new_point,false,sizeof(new_point));
}

void Simulate(int center_x, int center_y){
    //새 커브 초기화
    InitNewCurve();

    for(int i = 0 ; i <= GRID_MAX; i++){
        for(int j = 0 ; j <= GRID_MAX; j++){
            if(!curr_point[i][j]) continue;

            point next_point = Roate(i, j, center_x, center_y);

            new_point[next_point.x][next_point.y] = true;
        }
    }

    //새로운 포인트들 현재 포인트에 추가 
    for(int i = 0 ; i <= GRID_MAX; i++){
        for(int j = 0 ; j <= GRID_MAX; j++){
            if(!new_point[i][j]) continue;
            curr_point[i][j] = true;
        }
    }



}

void DrawCurve(int x , int y, int d, int g){
    InitCurCurve();

    int dx[DIR_NUM] = {0, -1, 0, 1};
    int dy[DIR_NUM] = {1, 0, -1, 0};

    //0차 커브 
    // int start_x = x, start_y =y;
    // int end_x = x + dx[d], end_y = y + dy[d];
    // curr_point[start_x][start_y]=true;
    // curr_point[end_x][end_y]=true;
    point start = point{x,y};
    point end = point{ x + dx[d],y + dy[d]};
    curr_point[start.x][start.y]=true;
    curr_point[end.x][end.y]=true;

    // g차까지 커브 확장 
    while(g--){
        Simulate(end.x,end.y); //이전 차수의 끝점이 다음 차수의 센터 

        // 다음 차수 센터는
        // 기존 start가 end 기준 cw 90' 회전한 위치 
        // => 전체 과정이 센터(end)가 뭐인지만 바뀌고 시작점은 계속 같네, 시작점이 뭘 기준으로 돌지만 정해
        end = Roate(start.x,start.y,end.x,end.y);
    }

    // g차 커브 점들 paper에 다 표시 
    for(int i = 0 ; i <= GRID_MAX; i++){
        for(int j = 0 ; j <= GRID_MAX; j++){
            if(!curr_point[i][j]) continue;
            paper[i][j] = true;
        }
    }
}

int GetSquareSum(){
    //4개 꼭지점이 전부 커브인 칸 개수 
    // 크기 1인 정사각형!!!
    int ans = 0;
    for(int i = 0 ; i < GRID_MAX; i++){
        for(int j = 0 ; j < GRID_MAX; j++){
            if(paper[i][j] && paper[i+1][j] && paper[i][j+1]&& paper[i+1][j+1] ) ans++;
            
        }
    }
    return ans;

}

void Input(){
    cin>>N;
    for(int i = 0; i < N ; i++){ 
        int x,y,d,g;
        cin >> x >> y>> d >> g;
        DrawCurve(x,y,d,g);
    }
   
}


void Solve(){
    Input();
     cout<<GetSquareSum();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    Solve();
    return 0;
}
