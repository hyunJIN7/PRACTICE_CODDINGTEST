#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> convertBase(int n, int k){
    vector<int> ret; 
    while(n){
        ret.push_back(n%k);
        n/=k;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int isPrime(long long n){
    if(n<=1) return 0;
    for(long long i = 2 ; i*i <= n; i++){
        if( !(n%i) ) return 0;
    }
    return 1;
}


int solution(int n, int k) {
    int answer = 0;
    
    vector<int> convert = convertBase(n,k);
    long long cur = 0;
    for(int e : convert){
        if(!e){
            answer += isPrime(cur);
            cur=0;
        }
        cur = cur*10 + e;
    }
    answer += isPrime(cur);
    return answer;
}
