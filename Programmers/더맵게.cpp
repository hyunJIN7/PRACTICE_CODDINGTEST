#include <string>
#include <vector>
#include <queue>
#include <iostream>
typedef long long ll;
using namespace std;
//  https://leeminju531.tistory.com/21
int solution(vector<int> scoville, int K) {
    ll answer = 0;
    priority_queue <ll,vector<ll>,greater<ll>> pq(scoville.begin(),scoville.end());
    while(1){
        if(pq.top() >= K) return answer; //원소 1개일때 바로 K 넘는 경우도 있으니 
        if(pq.size()<2) break;    
        
        ll fir = pq.top(); pq.pop();
        ll sec = pq.top(); pq.pop();
        if(  !fir and !sec ) //맨위에 2개가 0이면 -1   !(fir || sec)
            break;

        
        
        ll mix = fir + sec*2;
        pq.push(mix);
        answer++;      
    }
    answer=-1;
    
    return answer;
}
