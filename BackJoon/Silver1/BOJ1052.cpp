//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*

n & (n-1) 연산 의미  
2진수에서 가장 오른쪽 가져오는/버리는 연산 
n = 1100 
n-1 = 1011
--> 1000

N&(-N) 연산 의미  
n = 001  -n =  111   --->    n&-n = 001
n = 010  -n =  110   --->    n&-n = 010
n = 100  - n = 100   --->    n&-n = 100

bit가 1인 녀석중 가장 오른쪽을 가져오는 연산
*/



int N,K;
int ans=0;

int BinaryCount(int n){ // 2진수에서 1의 개수 리턴 
	int cnt = 0;
	
	for(int i = 0 ;  n != 0 ; i++){
		n = n & (n-1);
		
		cnt++;
	}
	
	return cnt;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>N>>K;

	while(1){
		if (BinaryCount(N)<=K){
			cout<<ans;
			return 0;
		}
		else{
			int add = N&(-N);
			ans+= add;
			N+= add;
		}
		
	}
		
}
