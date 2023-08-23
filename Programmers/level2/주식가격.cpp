#include <string>
#include <vector>
#include <stack>

using namespace std;
//문제 이해를 나보다 작은 것이 얼마 후에 나오나 
vector<int> solution(vector<int> prices) {
    int len = prices.size();
    vector<int> answer(len);
    stack<int> st;
    
    for(int i = 0 ; i < len; i++){
        
        while(!st.empty() && prices[i] < prices[st.top()]){
            // stack 보다 작은 수 들어오면
            answer[st.top()] = i-st.top();
            st.pop();
        }
        st.push(i);
    }
    
    //stack에 남은 수는 len 대상으로 한번더 while 진행
    while(!st.empty()){
        answer[st.top()] = len - st.top() -1;
        st.pop();
    }
    
    
    return answer;
}
