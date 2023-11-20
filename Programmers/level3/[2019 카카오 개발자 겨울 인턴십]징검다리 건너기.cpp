// https://yabmoons.tistory.com/632
// sliding windowm maximum 방법으로 해결
// 이분탐색으로도 가능 
/* 이분탐색
전체 돌 무게 0 , max
mid : 돌 무게 중간 값
mid 값으로 전체 빼고 0이하 몇개 연속하는지 카운트 하고
이렇게 이분탐색 진행
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 987654321;
    deque<pair<int,int>> dq;
    
    for(int i = 0 ; i < stones.size(); i++){
        //범위 벗어났으면 빼기
        while(!dq.empty() && dq.front().second < i - k + 1)
            dq.pop_front();
        //새로 들어오는게 더 크면 뒤 부터 후보 다 없애고 
        //다음 구간의 새로운 후보가 되거나 max 값 되기 
        while(!dq.empty() && dq.back().first < stones[i])
            dq.pop_back();
        
        dq.push_back({stones[i], i});
        if(k-1 <=i && dq.front().first < answer)
            answer = dq.front().first;   
    }  
    return answer;
}
