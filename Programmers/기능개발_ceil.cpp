#include <string>
#include <vector>
#include <cmath>  // ceil
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int prior_period = ceil((100.0-progresses[0])/speeds[0]);
    int cnt = 1;
    for(int i = 1 ; i < progresses.size(); i++){
        int period = ceil((100.0-progresses[i])/speeds[i]);
        if(prior_period < period){
            answer.push_back(cnt);
            cnt=1;
            prior_period= period;    
        }
        else{
            cnt++;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}
