#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer,num;
    
    int sum = 0, tmp = 0;
    for(int i = 0 ; i < s.length()-1 ; i++){
        if(s[i] == '}'){
            sum+=tmp;
            answer.push_back(sum);
            sum = 0, tmp =0;
        }
        else if(isdigit(s[i])){
            tmp = tmp * 10 + s[i] - 48;
        }
        else if(s[i]==',' && s[i+1] != '{' ){
            sum+=tmp;
            tmp = 0;
        }
    }
    sort(answer.begin(),answer.end());
    for(int i = answer.size()-1 ; i > 0; i--){
        answer[i] -= answer[i-1];
    }
    
    return answer;
}
