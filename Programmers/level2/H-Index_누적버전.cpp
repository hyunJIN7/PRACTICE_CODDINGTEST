#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int maxCitation=0;
    int cntCitation[10002]={0,};
    for(auto e : citations){
        cntCitation[e]++;
        maxCitation = max(maxCitation,e);
    }
    for(int i = maxCitation; i >=0; i--){
        cntCitation[i]+= cntCitation[i+1];
        if( i <=cntCitation[i]){
            answer=i;
            break;
        }
    }

    return answer;
}
