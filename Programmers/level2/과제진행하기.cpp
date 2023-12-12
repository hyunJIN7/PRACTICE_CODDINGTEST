#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct subject{int start; int play; string name;};

bool cmp(subject a, subject b){ return a.start < b.start;}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<subject> new_plans;
    
    for(auto vec : plans){
        int start = stoi(vec[1].substr(0,2)) * 60 + stoi(vec[1].substr(3));
        new_plans.push_back({start, stoi(vec[2]), vec[0]});
    }
    sort(new_plans.begin(), new_plans.end(), cmp);
    
    stack<pair<int,string>> rest_stack;
    
    for(int i = 0 ; i < new_plans.size() - 1; i++){
        int curr_start = new_plans[i].start;
        int play = new_plans[i].play;
        int next_start = new_plans[i+1].start;
        int rest_time = next_start - (curr_start + play);
        
        if(rest_time < 0){ // 끝나는 시간이 넘는다면
            rest_stack.push({ -rest_time , new_plans[i].name});
            continue;
        } 
        //다음 시작 시간 안넘고 남는다면
        answer.push_back(new_plans[i].name);
        while(!rest_stack.empty()){
            int stack_time = rest_stack.top().first;
            string stack_name = rest_stack.top().second;
            rest_stack.pop();
            if(stack_time > rest_time){
                rest_stack.push({stack_time - rest_time, stack_name});
                break;
            }
            rest_time-=stack_time;
            answer.push_back(stack_name);
        }
        
        
    }
    
    //맨 마지막 시작하는 원소는 그냥 넣기 
    answer.push_back(new_plans[new_plans.size() - 1].name);
    while(!rest_stack.empty()){
        answer.push_back(rest_stack.top().second);
        rest_stack.pop();
    }

    return answer;
}
