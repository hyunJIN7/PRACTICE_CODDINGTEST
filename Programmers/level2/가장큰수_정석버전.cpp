#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int id=0;
    char biggest = 0;
    
    for (int i = 0; i < number.size(); ++i){
        if(biggest < number[i]){
            biggest = number[i];
            id = i;
        }
        if(i==k){
            k++;
            answer+=biggest;
            biggest=0;
            i = id;
        }

    }   
    return answer;
}
