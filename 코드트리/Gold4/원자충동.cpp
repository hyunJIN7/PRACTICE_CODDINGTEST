#include <iostream>
#include <queue>

#define MAX_N 50
#define MAX_S 1000
#define DIR_CNT 8
#define SPLIT_ATOM_CNT 4

using namespace std;

struct atom{int m,s,d;};//질량m 속력s 방향d 

int N,M,K;
queue<atom> que[MAX_N][MAX_N];

int dy[DIR_CNT]={-1,-1,0,1,1, 1,0, -1};
int dx[DIR_CNT]={ 0, 1,1,1,0,-1,-1,-1};

void Input(){
    cin>>N>>M>>K;
    for(int i = 0,m,s,d,y,x ; i < M ; i++){
        cin>>y>>x>>m>>s>>d;
        que[y-1][x-1].push(atom{m,s,d});
    }
}

void Move(){ //질량m 속력s 방향d 
    queue<atom> moved[MAX_N][MAX_N];
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            
            while(!que[i][j].empty()){
                atom target = que[i][j].front();
                int y = ( i + target.s* dy[target.d] + MAX_S*N ) % N;
                int x = ( j + target.s* dx[target.d] + MAX_S*N ) % N;
                moved[y][x].push(target);
                que[i][j].pop();

            }
            
        }
    }
    //copy
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            que[i][j]=moved[i][j];
        }
    }
}

void Synthesize(){
    queue<atom>sythesized;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(que[i][j].empty() || que[i][j].size() < 2 ) continue;
            
            //합성 
            int cnt = que[i][j].size();
            int mass=0,speed=0;
            // int pre_dir=que[i][j].front().d, dir = 0;//일치
            int dir_type[2]={0,0};

            for(int k = 0 ; k < cnt; k++){
                atom target = que[i][j].front();
                
                mass += target.m;
                speed += target.s;
                dir_type[target.d%2]++;
                // if(!dir && pre_dir%2 != target.d%2) dir = 1;           
                que[i][j].pop();
            }

            //합성 원자 분해
            mass /= 5;
            speed /= cnt;
            if(! mass) continue; // 소멸 
            int dir (!dir_type[0] || dir_type[1]) 0 : 1;
            // 전부 상하좌우 or 대각선이면 둘 중 하나는 true 나오니까 

            for(int k= 0 ; k < SPLIT_ATOM_CNT ; k++){
                que[i][j].push(atom{mass, speed, dir + k*2});
            }

        }
    }

}

int GetAtomMassSum(){
    int sum = 0 ;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            while(!que[i][j].empty()){
                sum += que[i][j].front().m;
                que[i][j].pop();
            }
            
        }
    }
    return sum;
}


void Solve(){
    Input();
    while(K--){
        Move();
        Synthesize();
    }
    cout<<GetAtomMassSum();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    Solve();
    return 0;
}
