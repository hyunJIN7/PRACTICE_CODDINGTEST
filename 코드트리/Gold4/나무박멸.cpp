#include <iostream>
#include <tuple>

#define MAX_N 20
#define MAX_K 20
#define DIR_NUM 4

using namespace std;

int N,M,K,C; // 격자 크기, 박멸 진행 년 수, 제초제 확산 범위, 제초제 수명 
int tree[MAX_N][MAX_N];
int life[MAX_K][MAX_K] = {0,}; // 제초제 위치,수명

int ans = 0;// 박멸한 그루 수 

bool InRange(int y, int x){
    return 0 <= y && y < N && 0 <= x && x < N;
}

void MinusWeedLife(){
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            if(life[i][j] > 0) life[i][j]--;
        }
    }
}

tuple<int,int,int> SearchMaxWeed(){
    int max_tree=0, max_y=0, max_x=0;
    int dy[DIR_NUM] = {-1, -1, 1, 1};
    int dx[DIR_NUM] = {-1, 1, 1, -1};

    // 어느 칸이 가장 많이 박멸하는지 확인 
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            if( tree[i][j] <= 0 ) continue;
            //나무가 있는 곳이면 대각선 제초 가능 수 확인하기 
            int cnt = tree[i][j]; // 본인 칸 포함해야함. 
            for(int d = 0; d < DIR_NUM; d++){
                for(int k = 1; k <= K; k++){ // 대각선 K칸
                    int ny = i + k * dy[d];
                    int nx = j + k * dx[d];
                    if(InRange(ny,nx) && tree[ny][nx] > 0 ){
                        cnt += tree[ny][nx];
                    }
                    else break;
                }
            }

            if(max_tree < cnt){
                max_tree = cnt;
                max_y = i;
                max_x = j;
            }
            
        }
    }   
    return {max_tree , max_y , max_x};
}

//제초
void Weed(){
    int max_tree=0, max_y=0, max_x=0;
    tie(max_tree , max_y , max_x) = SearchMaxWeed();

    int dy[DIR_NUM] = {-1, -1, 1, 1};
    int dx[DIR_NUM] = {-1, 1, 1, -1};

    ans += max_tree;
    tree[max_y][max_x] = 0;
    life[max_y][max_x] += C + 1;
    for(int d = 0; d < DIR_NUM; d++){
        for(int k = 1; k <= K; k++){ // 대각선 K칸
            int ny = max_y + k * dy[d];
            int nx = max_x + k * dx[d];
            
            if(InRange(ny,nx)){
                life[ny][nx] = C + 1; //있던 곳에 또 뿌리면 수명 연장이 아닌, 해당 시점에서 C년 기간만 살아있음  
                if(tree[ny][nx] > 0){
                    tree[ny][nx] = 0;
                }
                else break;
            }
        }
    }
}


//번식
void Breed(){
    int dy[DIR_NUM] = {0,0,1,-1};
    int dx[DIR_NUM] = {1,-1,0,0};
    int new_tree[MAX_N][MAX_N]={0,};
    
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            if( tree[i][j] <= 0 ) continue;
            int cnt = 0;

            for(int d = 0; d < DIR_NUM; d++){
                int ny = i + dy[d];
                int nx = j + dx[d];
                if(InRange(ny,nx) &&  !tree[ny][nx] && !life[ny][nx] )
                    cnt++;     
            }

            for(int d = 0; d < DIR_NUM; d++){
                int ny = i + dy[d];
                int nx = j + dx[d];
                if(InRange(ny,nx) &&  !tree[ny][nx]&& !life[ny][nx] )
                    new_tree[ny][nx] += tree[i][j] / cnt;
            }
            
        }
    }
    //번식한거 더하기 
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            tree[i][j] += new_tree[i][j];
        }
    }
}

//나무 성장
void Grow(){
    int dy[DIR_NUM] = {0,0,1,-1};
    int dx[DIR_NUM] = {1,-1,0,0};
    
    int new_tree[MAX_N][MAX_N]={0,};
    
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            if( tree[i][j] <= 0 ) continue;
            int cnt = 0;
            for(int d = 0; d < DIR_NUM; d++){
                int ny = i + dy[d];
                int nx = j + dx[d];
                //주변에 나무 있다면 성장 
                if(InRange(ny,nx) &&  tree[ny][nx] > 0)
                    cnt++;
            }
            new_tree[i][j] += cnt;
        }
    }

    //tree에 new_tree 값 더하기 
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            tree[i][j] += new_tree[i][j];
        }
    }
}

void Input(){
    cin >> N >> M >> K >> C;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            cin>>tree[i][j];
        }
    }
}

void Solve(){
    Input();
    for(int i = 0 ; i < M ; i++){
        Grow();
        Breed();
        Weed(); // 제초제 수명 c+1로 주기 
        MinusWeedLife();
    }
    cout<<ans;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();
    return 0;
}
