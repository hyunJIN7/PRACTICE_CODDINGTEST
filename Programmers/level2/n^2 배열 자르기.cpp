#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(; left <= right ; left++){
        // if(left % n < i){
        //     answer.push_back(left/n+1);
        // }
        // else{
        //     answer.push_back(left % n +1 );
        // }
        answer.push_back(max(left/n,left%n)+1);
    }    
    return answer;
}
