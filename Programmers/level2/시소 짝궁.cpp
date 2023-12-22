#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
long long solution(vector<int> weights) {
    long long answer = 0;
    
    sort(weights.begin(),weights.end());
    
    vector<int> distances = {2, 3, 4};
    map<int,ll> weight_cnt,token_cnt;
    
    for(int w : weights){
        weight_cnt[w]++;
        for(int d : distances)
            token_cnt[w*d]++;          
    }    
    
    for(auto t : token_cnt)
        if(t.second >= 2) 
            answer += t.second * (t.second - 1) / 2;  
    
    //같은 수에 대한 중복 제거 
    for(auto w : weight_cnt)
        answer -=  w.second * (w.second - 1);
    
    return answer;
}
