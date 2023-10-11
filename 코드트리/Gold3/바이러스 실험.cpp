/*
vec[i][j].size() == 0 쓰지 말기, 결과가 달라짐.....왜..
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 10
#define DIE_AGE 2
#define BREED_AGE 5
#define DIR_NUM 8

using namespace std;

int N,M,K;

int food[MAX][MAX];
int next_food[MAX][MAX];

vector<int> virus[MAX][MAX];
vector<int> next_virus[MAX][MAX];

int delta[MAX][MAX];

int dx[DIR_NUM] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[DIR_NUM] = {-1,  0,  1, -1, 1, -1, 0, 1};

bool InRange(int y, int x){
    return 0 <= y && y < N && 0 <= x && x < N;
}

void Out(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << food[i][j] <<" ";
        }
        cout<<"\n";
    }
}

void Simulate(){
    //초기화 
    memset(next_food,0,sizeof(next_food) );
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++) 
            next_virus[i][j].clear();

    //step 1 양분섭취 
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){

            sort(virus[i][j].begin(), virus[i][j].end());            
            for(int s = 0; s < virus[i][j].size(); s++){
                if(virus[i][j][s] <= food[i][j]){
                    //양분 섭취
                    next_virus[i][j].push_back(virus[i][j][s] + 1);
                    food[i][j] -= virus[i][j][s];
                }
                else{
                    next_food[i][j] += virus[i][j][s] / 2 ; 
                }
            } 
            //남은 양분 넣어주기 
            next_food[i][j] += food[i][j];

        }
    }


    // step 2. 번식
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            for(int s = 0; s < next_virus[i][j].size(); s++){
                //5의 배수만 
                if(next_virus[i][j][s] % 5) continue;
                
                for(int d = 0 ; d < DIR_NUM; d++){
                    int ny = i + dy[d], nx = j + dx[d];
                    if(InRange(ny,nx))
                        next_virus[ny][nx].push_back(1);       
                    
                } 
            }
        }
    }

    // step 3. 양분 추가
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            next_food[i][j] += delta[i][j];
        }
    }


    // 바이러스와 양분 갱신 
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            food[i][j] = next_food[i][j] ;
            virus[i][j] = next_virus[i][j];

        }
    }




}

void Input(){
    cin >> N >> M >> K;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin >> delta[i][j];
            food[i][j] = 5; // 초기값 5라서 
        }
    }

    while(M--){
        int r,c,a;
        cin >> r >> c >> a;
        virus[r - 1][c - 1].push_back(a);
    }
}


void Solve(){
    Input();

    while(K--)  
        Simulate();
    
    int ans = 0;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            ans += (int)virus[i][j].size();
    
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    Solve();
    return 0;
}
