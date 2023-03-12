#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int pre_period=0;
    for(int i = 0 ; i < speeds.size();i++){
        int period = (99-progresses[i])/speeds[i] + 1;
        
        if(pre_period < period || answer.empty())
            answer.push_back(1);
        else ++answer.back();
        
        if(pre_period < period) pre_period = period;
        
      
    }
    
    return answer;
}
