#include <iostream>
#include <cmath>
#include <vector>

#define NUM_PEOPLE 8
#define NUM_CHAIR 4
using namespace std;

int Chair[NUM_CHAIR][NUM_PEOPLE];
int Index[NUM_CHAIR]={0,0,0,0}; // Chair의 북쪽 자리 위치


void Input(){
    string input;
    for(int i = 0 ; i < NUM_CHAIR ; i++){
        cin>>input;
        for(int j = 0 ; j < NUM_PEOPLE ; j++){
            Chair[i][j] = input[j]-'0';
        }
    }
}

void RotateChair(int target_chair, int dir){//회전시킬 의자, 방향 --> Index 값만 바꾸는 것 
    int num = (dir==1)?  NUM_PEOPLE-1 : 1;
    Index[target_chair] = (Index[target_chair]   +  num ) % NUM_PEOPLE;
}

int GetAdjectIndex(int target_chair, int Interval){
    return (Index[target_chair]+Interval) % NUM_PEOPLE;
}

void Solution(int target_chair, int dir){
    vector<pair<int,int>> roate_target;
    roate_target.push_back({target_chair,dir});
    //기준 의자의 왼쪽
    for(int i = target_chair-1, d = dir ;  i>=0 ; --i){
        //인접 위치 출신 다르면
        if(Chair[i][ GetAdjectIndex(i,2)] == Chair[i+1][ GetAdjectIndex(i+1,6) ] ) break;
        d*=-1;
        roate_target.push_back({i,d});
    }
    //기존 의자의 오른 
    for(int i = target_chair+1,d=dir; i < NUM_CHAIR; ++i){
        if(Chair[i][ GetAdjectIndex(i,6) ] == Chair[i-1][GetAdjectIndex(i-1,2)]) break;
        d*=-1;
        roate_target.push_back({i,d});
    }

    // 회전 대상 회전
    for(int i = 0 ; i < roate_target.size() ; i++){
        RotateChair(roate_target[i].first, roate_target[i].second);
    }

}


int GetScore(){
    int score = 0;
    for(int i = 0 ; i < NUM_CHAIR; i++){
        score += pow(2,i) * Chair[i][Index[i]];
    }
    return score;
}

void Solve(){
    Input();
    int testcase;
    cin>>testcase;
    while(testcase--){
        int target_chair,d;
        cin>>target_chair>>d;
        Solution(target_chair-1,d);
    }
    //출력
    cout<<GetScore();
}

int main() {
    Solve();
    return 0;
}
