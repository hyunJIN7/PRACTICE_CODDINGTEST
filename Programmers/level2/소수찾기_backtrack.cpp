#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

string target;
bool visited[7]={0,};
char arr[7];
set<int> S;

bool isPrime(int n){
    if(n<=1) return false;
    if(n==2) return true;
    for(int i = 2 ;i <= sqrt(n);i++)if(!(n%i)) return false;
    return true;
}

void backtrack(int len,int index){
    
    arr[len]=target[index];
    int num=0;
    for(int i = 0 ; i <= len ; i++){
        num = num*10 + arr[i]-'0';
    }
    if(isPrime(num)){
        S.insert(num);
    }
    
    if(len==target.length()-1) return;
    
    for(int i = 0 ; i < target.length(); i++){
        if(visited[i]) continue;
        visited[i]=true;
        backtrack(len+1,i);    
        visited[i]=false;
    } 
}

int solution(string numbers) {
    target = numbers;
    
    for(int i = 0 ; i < numbers.length();i++){
        visited[i]=true;
        backtrack(0,i);
        visited[i]=false;
    }

    return S.size();
}
