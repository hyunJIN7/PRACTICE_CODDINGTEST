#include <iostream>
#define MAX 50
using namespace std;

int map[MAX][MAX];
int N,M,ans=0;
int y,x,d;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
bool visited[MAX][MAX]={0,};

void Input(){
    cin>>N>>M;
    cin>>y>>x>>d;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>map[i][j];
        }
    }
    visited[y][x]=true;
    ans++;
}

void Solution(){      
    int i = 0;
    
    while(1){
        d = (d+3)%4;// 좌회전 
        int ny = y+dy[d], nx = x+dx[d];
        i++;
        if( !visited[ny][nx] && !map[ny][nx]){
            y=ny;
            x=nx;
            visited[y][x]=true;
            ans++;
            i=0;
            continue;
        }

        if(i>=4){
            //후진 
            y = y - dy[d];
            x = x - dx[d];
            i=0;
            if(map[y][x]) return;
        }

    }

}

void Solve(){
    Input();
    Solution();
    cout<<ans;
}

int main() {
    Solve();
    return 0;
}
