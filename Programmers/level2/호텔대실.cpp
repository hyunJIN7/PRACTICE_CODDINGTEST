#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(book_time.begin(), book_time.end());
    for(auto vec : book_time){
        int sT = stoi(vec[0].substr(0,2))*60 + stoi(vec[0].substr(3,2));
        int eT = stoi(vec[1].substr(0,2))*60 + stoi(vec[1].substr(3,2)) + 10;
        
        while(!pq.empty() && pq.top() <= sT){
            pq.pop();
        }
        
        pq.push(eT);
        answer = max(answer ,(int)pq.size() );
    }
    return answer;
}
