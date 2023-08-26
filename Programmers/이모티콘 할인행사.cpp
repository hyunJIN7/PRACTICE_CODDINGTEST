#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int N;
int visited[7]={0,};
float discount[7];
vector<vector<float>> discountList;
void dfs(int index, int target){ //(target+1)*0.1이 할인rate
    if(index==N){
        discountList.push_back(vector<float>(discount,discount+N)) ;
        return;
    }    

    for(int i = 0; i < 4 ; i++){
        if(visited[i] == N) continue;
        visited[i]++;
        discount[index] = (i+1)*0.1;
        dfs(index+1, i);
        visited[i]--;
        
    }
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    N = emoticons.size();
    vector<int> answer(2);
     
    dfs(0,0);
    
    for(auto disc : discountList ){ // 할인율 조합 
        int eCost = 0;//이모티콘 수인 
        int epCnt = 0;// 플러스 가입자 
        for(auto user : users){ 
            int cost = 0; // 유저 한명에 대한 이미티콘 가격
            for(int i = 0 ; i < N ; i++){
                if(disc[i]*100 < user[0]) continue; //할인율 기준 못 넘김
                cost+= (1-disc[i])*emoticons[i];
            }
            
            if(user[1] <= cost){//기준 가격 넘길 때
                epCnt++;
            }
            else{
                eCost+=cost;
            }
        }
        
        if(answer[0] < epCnt){
            answer[0] = epCnt;
            answer[1] = eCost;
        }else if(answer[0] == epCnt && answer[1] < eCost){
            answer[1] = eCost;
        }
        
    }
    

    
    
    return answer;
}
