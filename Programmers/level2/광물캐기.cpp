#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>


using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int N =(picks[0]+picks[1]+picks[2])*5;
    priority_queue<int> pq;

    map<string,int> m;
    m["diamond"]=100,m["iron"]=10,m["stone"]=1;
    
    for(int i = 0,sum=0 ; i < N && i  <  minerals.size();i++){
        sum+= m[minerals[i]];
        if( !((i+1)%5) || i+1== minerals.size()){
            pq.push(sum);
            sum=0;
        }
    }
    
    while(!pq.empty()){
        int mineral = pq.top();
        pq.pop();     
        if(picks[0]){
            answer +=  (mineral/100 +   mineral%100/10   + mineral%10) ;
            picks[0]--;
        }
        else if(picks[1]){
            answer +=  (mineral/100 * 5  +   mineral%100/10   + mineral%10) ;
            picks[1]--;
        }
        else if (picks[2]){

            answer +=  (mineral/100 * 25  +   mineral%100/10 *5  + mineral%10) ;
            picks[2]--;

        }                
    }
    
    
    return answer;
}
