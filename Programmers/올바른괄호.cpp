#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int num = 0;
    for(char e : s){
        if(e=='('){
            num++;
        }
        else{
            num--;
            if(num<0) return false;
        }
    } 
    return !num;
}
