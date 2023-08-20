#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int time[1450]={0,};
    
    for(auto vec : book_time){
        int s = stoi(vec[0].substr(0,2)) * 60 + stoi(vec[0].substr(3,2));
        int e = stoi(vec[1].substr(0,2)) * 60 + stoi(vec[1].substr(3,2))+10;
        e = (1440 < e) ? 1440 : e ;
        for(int i = s; i < e ; i++) time[i]++;
    }
    for(int i = 0 ; i < 1450 ; i++){
        if(answer < time[i]) answer = time[i];
    }
    
    return answer;
}
