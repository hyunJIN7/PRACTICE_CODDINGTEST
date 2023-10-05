#include <iostream>
#include <queue>
#include <cstring>

#define MAX_N 50
#define MAX_M 10
#define MAX_ANS 2501

using namespace std;

int N,M;
int map[MAX_N][MAX_N];
int hospital_cnt=0; // 총 병원 수 
int hospital_pose[MAX_M][2];//병원 위치 
int hospital_combi[MAX_M]={0,}; //M개 병원 조합 
bool visited[MAX_N][MAX_N];
int virus_cnt = 0;
int ans = MAX_ANS;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
struct node{int y,x,t;};

bool InRange(int y, int x){
    return 0 <= y && y < N && 0 <= x && x < N;
}

void Input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>map[i][j];
            if(!map[i][j]) virus_cnt++;
            else if(map[i][j]==2){
                hospital_pose[hospital_cnt][0]=i;
                hospital_pose[hospital_cnt][1]=j;
                hospital_cnt++;
            }
        }
    }
}

void BFS(){
    int max_time=0;
    int cnt=0;
    queue<node> q;
    
    // 병원 위치 
    for(int i = 0 ; i < M ; i++){
        int target = hospital_combi[i];
        int y = hospital_pose[target][0];
        int x = hospital_pose[target][1];
        q.push(node{y,x,0});
        visited[y][x]=true;
    }

    while(!q.empty()){
        int cy = q.front().y;
        int cx = q.front().x;
        int ct= q.front().t;
        q.pop();

        for(int i = 0 ; i < 4 ; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            //선택 안한 병원 지나가는 것 가능 
            if(!InRange(ny,nx) || map[ny][nx]==1 || visited[ny][nx]) continue;
            
            visited[ny][nx] = true;
            q.push(node{ny,nx,ct+1});
            if(!map[ny][nx]) { 
                // 바이러스에 대해서만 진행해야함.
                cnt++;//바이러스 다 제거했다 개수 체크
                max_time = (max_time <= ct)?ct+1:max_time;
            }
        }

    }

    if(cnt==virus_cnt){
        ans = (max_time < ans) ? max_time : ans;
    }

}

void GetCombination(int depth, int start){
    if(depth==M){
        memset(visited,false,sizeof(visited));
        BFS();
    }

    for(int i = start ; i < hospital_cnt ; i++){
        hospital_combi[depth] = i;
        GetCombination(depth+1,i+1);
    }
}

void Solve(){
    Input();

    GetCombination(0,0);
    if(ans==MAX_ANS) cout<<-1;
    else cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Solve();

    return 0;
}
