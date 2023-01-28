#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map <int,int> m;
priority_queue<int> cnt;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(int e : tangerine){
        m[e]++;
    }
    for(auto c : m){
        cnt.push(c.second);
    }
    
    int sum = 0;
    while(!cnt.empty()){
        sum+=cnt.top();
        answer++;
        if(sum>=k){
            return answer;
        }
        cnt.pop();      
    }  
    return answer;
}
