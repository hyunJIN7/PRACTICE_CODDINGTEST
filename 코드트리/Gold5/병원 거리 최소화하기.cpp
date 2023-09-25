#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define MAX 50
using namespace std;

int N,M,ans=987654321;
int map[MAX][MAX];


struct node{int y,x;};
vector<node> hospital,client;
int combi[MAX];
bool visited[MAX]={0,};

int getABS(int a,int b ){
    return (a-b < 0) ? b-a : a-b;
}

int getDis(node n1, node n2){
    return getABS(n1.x ,n2.x) + getABS(n1.y, n2.y);
}

void Input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0;  j < N ; j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                hospital.push_back(node{i,j});
            }
            else if(map[i][j]==1){
                client.push_back(node{i,j});
            }
        }
    }
}


int Simulation(){
    //각 고객 병원 쫙 돌고 제일 낮은 값들 sum 반환 
    int sum = 0;

    for(int i = 0 ; i <client.size(); i++){
        int dis = 987654321;
        for(int j = 0 ; j < M; j++){
            dis = min(dis, getDis(client[i], hospital[combi[j]]));      
        }
        sum+=dis;

    }
    return sum;
}

void Combination(int depth, int start){
    if(depth==M){
        ans = min(ans,Simulation());
        return;
    }

    for(int i = start ; i < hospital.size(); i++){
        if( visited[i]) continue;
        visited[i] = true;
        combi[depth] =  i;
        Combination(depth+1,i+1);
        visited[i] = false;

    }
}

void Solve(){
    Input();
    memset(visited,0,sizeof(visited));
    Combination(0,0);
    cout<<ans;
}

int main() {
    Solve();
    return 0;
}
