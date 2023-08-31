#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    for(int i = 0,len = elements.size(); i < len; i++){
        int sum=0;
        for(int j = 0; j < len; j++){
            sum+= elements[(i+j)%len];
            s.insert(sum);
        }
    }   
    return s.size();
}
