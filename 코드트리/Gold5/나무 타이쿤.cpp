#include <iostream>
#include <queue>
#include <cstring>

#define MAX 15
#define DIR_NUM 8

using namespace std;

int N,M;//크기,연도
int height[MAX][MAX];
bool tonic[MAX][MAX]={0,};

int dy[DIR_NUM]={0,-1,-1,-1,0,1,1,1};
int dx[DIR_NUM]={1,1,0,-1,-1,-1,0,1};

void Input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>height[i][j];
        }
    }
    //초기 영양 위치 
    tonic[N-1][0] = tonic[N-1][1] = tonic[N-2][0] = tonic[N-2][1] = true;

}

bool InRange(int y,int x){
    return 0 <= y && y < N && 0 <= x && x <N;
}

void Grow(){ // 영양제 성장
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(tonic[i][j]) height[i][j]++;
        }
    }
}

void GrowAdjacent(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(!tonic[i][j]) continue;
            int cnt = 0;
            for(int k = 1 ;  k <=7 ; k+=2){
                int y = i + dy[k];
                int x = j + dx[k];
                if(InRange(y,x)  && height[y][x] >= 1){
                    cnt++;
                }
            }
            height[i][j] += cnt;
        }
    }

}

void FindNewTonic(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(tonic[i][j]) {
                tonic[i][j]=false;
                continue;
            }
            else if(height[i][j]>=2){
                height[i][j]-=2;
                tonic[i][j]=true;
            }
        }
    }
}

void Move(int dir, int cnt){ // 이동한 위치 true, 원래 위치 false 
    queue<pair<int,int>> que; //기존 위치 
    for(int i = 0 ; i < N ; i++){  
        for(int j = 0 ; j < N ; j++){
            if(!tonic[i][j])continue;
            que.push({i,j});
            tonic[i][j]=false;
        }
    }
    while(!que.empty()){
        int y = ( que.front().first + dy[dir]*cnt + N )%N;
        int x = ( que.front().second + dx[dir]*cnt + N )%N;
        tonic[y][x]=true;
        que.pop();
    }
}



void Solution(int dir, int cnt){
    //영양제 이동
    Move(dir,cnt);

    //영양제 있는 곳 성장 
    Grow();

    //대각선 방향 성장.
    GrowAdjacent();
    
    //높이 2 이상 영양소 추가
    FindNewTonic();
}

int GetTotalHeight(){
    int sum = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            sum+=height[i][j];
        }
    }
    return sum;
}

void Solve(){
    memset(tonic,0,sizeof(tonic));
    Input();
    
    while(M--){
        int d,p;
        cin>>d>>p;
        Solution(d-1,p);
    }

    cout<<GetTotalHeight();
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    Solve();
    return 0;
}
