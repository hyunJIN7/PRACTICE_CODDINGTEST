#include <string>
#include <vector>
#include <map>
#include <iostream>

#define MAX 1000000
using namespace std;

int cnt[2][MAX];

int solution(vector<int> topping) {
    map<int,int> m1,m2;
    for(int i = 0 ; i < topping.size(); i++){
        if(i) cnt[0][i] = cnt[0][i-1];
        if(!m1[topping[i]])
            cnt[0][i]++, m1[topping[i]]++;
    }

    for(int i = topping.size()-1 ; i >= 0; i--){
        if(i != topping.size()) cnt[1][i] = cnt[1][i+1];
        if(!m2[topping[i]])
            cnt[1][i]++, m2[topping[i]]++;  
    }
    
    int answer = 0;
    for(int i = 0 ; i < topping.size() - 1; i++)
        if(cnt[0][i] == cnt[1][i + 1]) 
            answer++;
 
    return answer;
}
