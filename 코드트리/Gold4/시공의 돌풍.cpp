#include <iostream>
#define MAX 50
#define SPREAD 5

using namespace std;

int N,M,T;
int dust[MAX][MAX];
int cleaner[2]; //시공의 y 위치 

int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

void Input(){
    cin>>N>>M>>T;
    for(int i = 0,k=0 ; i < N ; i++){
        for(int j = 0; j < M ; j++){
            cin>>dust[i][j];
            if(dust[i][j]==-1)cleaner[k++]=i;  
        }
    }
}

bool InRange(int y, int x){
    return 0<= y && y < N && 0 <= x &&x <M;
}

void SpreadDust(){
    int tmp[MAX][MAX]={0,};
    //각 칸 확산 양 
    for(int i = 0,cnt=0 ; i < N ; i++){
        for(int j = 0; j < M ; j++){
            if(dust[i][j]==-1) continue;
            cnt=0;
            for(int k = 0 ; k < 4 ; k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(!InRange(ny,nx) || dust[ny][nx]==-1) continue;
                cnt++;
                tmp[ny][nx] += (dust[i][j]/SPREAD);
            }
            dust[i][j] -= (dust[i][j]/SPREAD)*cnt;
        }
    }
    //확산 양 더하기 
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M ; j++){
            dust[i][j]+=tmp[i][j];
        }
    }
}
 
void CleanDust(){
    int tmp[MAX][MAX]={0,};
    dust[cleaner[0]][0]= dust[cleaner[1]][0]= 0;
    // 좌우 이동 
    for(int i = 1 ; i < M; i++){
        tmp[0][i-1] = dust[0][i];
        tmp[N-1][i-1] = dust[N-1][i];

        //오른쪽
        tmp[cleaner[0]][M-i] =dust[cleaner[0]][M-i-1];
        tmp[cleaner[1]][M-i] =dust[cleaner[1]][M-i-1];
    }

    //돌풍 위쪽 양 사이드 
    for(int i = 0 ; i < cleaner[0] ; i++ ){
        //아래
        tmp[i+1][0]=dust[i][0];
        //위
        tmp[i][M-1]=dust[i+1][M-1];
    }

    //돌풍 아래 양 사이드 
    for(int i = cleaner[1] ; i < N-1 ; i++ ){
        //위
        tmp[i][0]=dust[i+1][0];
        //아래
        tmp[i+1][M-1]=dust[i][M-1];
    }
    tmp[cleaner[0]][0]= tmp[cleaner[1]][0]= -1;

    //값 복사 
    //세로
    for(int i = 0 ; i < N ; i++){
        dust[i][0] = tmp[i][0];
        dust[i][M-1] = tmp[i][M-1];
    }
    //가로
    for(int i = 1; i < M-1 ; i++){
        dust[0][i]=tmp[0][i];
        dust[cleaner[0]][i]=tmp[cleaner[0]][i];
        dust[cleaner[1]][i]=tmp[cleaner[1]][i];
        dust[N-1][i]=tmp[N-1][i];
    }
   
}

int GetSumDust(){
    int ans = 0;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M ; j++){
            if(dust[i][j]==-1)continue;
            ans+=dust[i][j];
        }
    }
    return ans;

}

void Solve(){
    Input();
    while(T--){
        SpreadDust(); 
        CleanDust();
    }
    cout<<GetSumDust();
}

int main() {
    Solve();
    return 0;
}
