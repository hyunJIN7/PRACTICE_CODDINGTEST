#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int N,L,R,ans = 0;
int map[50][50];
bool visited[50][50]={0,};
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};
bool flag = true;

void Input(){
    cin >> N >> L >>R;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
        }
    }

}

void BFS(int y,int x){
    int sum = 0;
    queue< pair<int,int> > que,target;
    que.push({y,x});
    visited[y][x] = true;
    while(!que.empty()){
        int cy = que.front().first;
        int cx = que.front().second;
        
        // 연결된 것들 
        target.push({cy,cx});
        sum+= map[cy][cx];
        que.pop();
        
        // 주변 체크 
        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i], nx = cx + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >=N || visited[ny][nx]) continue;
            if( abs(map[ny][nx] - map[cy][cx]) < L || abs(map[ny][nx] - map[cy][cx]) > R ) continue;
            flag = true;
            visited[ny][nx]=true;
            que.push({ny,nx});
        }

    }

    int num = sum / target.size();
    while(!target.empty()){
        map[target.front().first][target.front().second] = num;
        target.pop();
    }   

}

void Solution(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(visited[i][j]) continue;
            BFS(i,j);   
        }
    }
    if(flag) ans++;
}


void Solve(){
    Input();
    while(flag){
        flag = false;
        memset(visited,0,sizeof(visited));
        Solution();
    } 
    cout<<ans;
}

int main() {

   Solve();

    return 0;
}
