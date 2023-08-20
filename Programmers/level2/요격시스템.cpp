#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int s=100000000,e=0;
    sort(targets.begin(),targets.end());
    
    for(auto vec : targets){
        
        if(e <= vec[0]){ // 범위 벗어남
            answer++;
            s = vec[0];
            e = vec[1];
        }
        else{ // 겹침
            s = (s<vec[0])?vec[0]:s;
            e = (e<vec[1])?e:vec[1];
        }
        
    } 
    return answer;
}
