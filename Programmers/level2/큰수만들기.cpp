#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> v(number.begin(),number.end());
    k = number.size() - k;
    int index = -1;

    while(k){        
        index = max_element(v.begin()+index+1, v.end()-k+1) - v.begin();
        answer = answer + number[index];
        k--;
    }

    return answer;
}
