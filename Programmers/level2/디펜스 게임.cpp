#include <string>
#include <vector>
#include <queue>
#define MAX 1000000

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    priority_queue<int> pq;
    for(int i = 0 ; i < enemy.size(); i++){
        pq.push(enemy[i]);
        n -= enemy[i];
        if(0 <= n)
            answer = i + 1;
        else{
            if(0 < k){
                n += pq.top();
                pq.pop();
                k--;
                answer = i + 1;
            }
            else{
                answer = i;
                break;
            }
        } 

    } 
    
    return answer;
}
