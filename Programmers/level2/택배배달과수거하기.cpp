//https://velog.io/@yaaloo/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%ED%83%9D%EB%B0%B0-%EB%B0%B0%EB%8B%AC%EA%B3%BC-%EC%88%98%EA%B1%B0
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0L;   

    int delBox=0,pickBox=0;
    
    for(int i = n-1;i >= 0;--i){
        
        if(deliveries[i] || pickups[i]){ // 배달해야하는 박스가 있으면 
            delBox -= deliveries[i];
            pickBox -= pickups[i];
            
            if(delBox < 0 || pickBox < 0){
                
                int cnt = max( (-delBox-1) / cap + 1, (-pickBox-1) / cap + 1 );
                answer = answer + (long long)(cnt * (i + 1) * 2) ;
                
                delBox += cap*cnt;
                pickBox += cap*cnt;
            }
            
        }
            
    }

    return answer;
}
