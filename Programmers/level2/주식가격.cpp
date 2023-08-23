#include <string>
#include <vector>
#include <stack>

using namespace std;
// 문제 이해를 나보다 작은 것이 얼마 후에 나오나를 푸는 문제. 테스트 케이스가 너무 빈약 
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int len = prices.size();
    for(int i = 0 ; i< len ; i++){
        
        while(!s.empty() && prices[s.top()] > prices[i]){
            answer[s.top()]=i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()]=len-s.top()-1;
        s.pop();
    }
    
    return answer;
}
