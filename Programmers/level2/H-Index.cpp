#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/*
- 문제 조건에서 인용 수 max가 논문 수 보다 큼
- 인용된 논문 수가 인용 수를 넘어갈때 안용 논문 수 리턴 
        
*/
int solution(vector<int> citations) {
    sort(citations.begin(),citations.end(),greater<int>());//내림차순
    
    for(int i = 0 ; i < citations.size(); i++){
        if(citations[i]  < i+1){
            return i;
        }
    }
    
    return citations.size();
}
