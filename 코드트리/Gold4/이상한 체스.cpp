#include <iostream>
#include <cstring>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

#define MAX 8
#define DIR_NUM 4
#define CHESS_TYPE_NUM 5
#define RIVAL_NUM 6

using namespace std;


int N,M;
int min_area = INT_MAX;
vector<pair<int,int> > chess_pieces;
int board[MAX][MAX];

// 말 방향 표시 
int piece_dir[MAX][MAX]={0,};

bool visited[MAX][MAX];

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

//말 종류마다 북동남서 방향으로 이동 가능한지 표시 
bool can_move[CHESS_TYPE_NUM+1][DIR_NUM] = {
    {},
    {1,0,0,0},
    {0,1,0,1},
    {1,1,0,0},
    {1,1,0,1},
    {1,1,1,1}
};

bool InRange(int y, int x){
    return 0 <= y && y < N && 0 <= x && x < M;
}

bool CanGo(int y, int x){
    return InRange(y,x) && board[y][x] != RIVAL_NUM;
}

void Fill(int start_y,int start_x, int piece_num, int face_dir){

    for(int i = 0 ; i < DIR_NUM; i++ ){

        if(!can_move[piece_num][i]) continue;

        //움직일 수 있는 방향 이라면
        int dir = (face_dir + i) % DIR_NUM;
        int y = start_y;
        int x = start_x;

        while(true){
            visited[y][x] = true;
            y = y + dy[dir];
            x = x + dx[dir];
            if(!CanGo(y,x)) break;

        }

    }

}

int GetArea(){
    memset(visited,0,sizeof(visited));

    for(int i = 0 ; i < chess_pieces.size() ; i++){
        int y,x;
        tie(y,x) = chess_pieces[i];
        //위치 , 체스번호, 체스 방향 
        Fill(y, x, board[y][x] , piece_dir[y][x]);

    }

    //visited 채워진거 개수 세기
    int area = 0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M ; j++){
            //방문 안한 곳 찾기 
            if(!visited[i][j] && board[i][j] != RIVAL_NUM){
                area++;
            }
        }
    }


    return area;
}

// chess_pieces의 방향 정하기 위한 Backtracking
// cnt는 chess_pieces의 인덱스 
void SearchMinArea(int cnt){
    if(cnt == chess_pieces.size()){
        min_area = min(min_area, GetArea());
        return;
    }

    //방향 정할 타겟
    int y,x;
    tie(y,x) = chess_pieces[cnt];
    for(int i = 0; i < DIR_NUM; i++){
        piece_dir[y][x] = i;
        SearchMinArea(cnt+1); // 다음 거 방향 정하기 
    }

}


void Input(){
    cin >> N >> M;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M ; j++){
            cin>>board[i][j];
            if(1 <= board[i][j] && board[i][j] <= 5){
                chess_pieces.push_back({i,j});
            }
        }
    }
}

void Solve(){
    Input();
    SearchMinArea(0);
    cout<<min_area;
}

int main() {
    ios::sync_with_stdio(0);
    Solve();
    return 0;
}
