#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    long long sum1=0,sum2=0;
    queue<int> q1,q2;
    
    for(int e : queue1){
        sum1+=e;
        q1.push(e);
    }
    
    for(int e : queue2){
        sum2+=e;
        q2.push(e);
    }
    
    for(int i = 0 ;  i < 600000; i++ ){
        if(sum1 == sum2){
            answer = i;
            break;
        }else if(sum1 > sum2){
            int num = q1.front();
            q1.pop();
            q2.push(num); 
            sum1-=num;
            sum2+=num;
        }else{
            int num = q2.front();
            q2.pop();
            q1.push(num);   
            sum2-=num;
            sum1+=num;
        }       
    }  
    return answer;
}
