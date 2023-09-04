#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    
    for(auto o : operations){
        if(o == "D 1" && ms.size()>0){
            ms.erase(--ms.end());
        }else if(o == "D -1" && ms.size()>0){
            ms.erase(ms.begin());
        }else if(o[0] == 'I'){
            ms.insert(stoi(o.substr(2, o.size()-2)));
        }
    }
    if(ms.size() == 0)
        return {0, 0};
    else
        return {*(--ms.end()), *ms.begin()};
}
