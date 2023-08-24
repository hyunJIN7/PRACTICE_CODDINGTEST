#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    map<int,int> m;
    vector<int> answer;
    
    int tmp=0;
    for(char c : s){
        if('0' <= c &&  c<='9'){
            tmp = tmp*10 + c - 48;
        }
        else{
            if(tmp){
                m[tmp]++;
                tmp= 0 ;   
            }
        }
    }
    
    vector<pair<int,int>> vec;
    for(auto e : m){
        vec.push_back({e.second,e.first});
    }
    sort(vec.begin(),vec.end());
    for(int i = vec.size()-1; i>=0 ; i--) answer.push_back(vec[i].second)    ;
    
    return answer;
}
