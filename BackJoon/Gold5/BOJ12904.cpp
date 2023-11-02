#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

/*
 T -> S 방향으로 
 만약 T[i]가 A라면 
 S[i-1] -> S[i] : A추가, 이렇게 연산이 정해진다.  
*/


int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	string S,T;
	cin >> S >> T;
	int Slen = S.size(),Tlen = T.size();
	
	int op[MAX]; // index : s ~ Tlen-1 까지   
	
	//어떤 연산 해야하는지  	
	// 해당 연산에 맞게 바꿔서 T와 같나 확인	 
	for(int i = Tlen - 1 ; Slen <= i; i--){
		op[i] = (T[i] == 'A')? 0 : 1;		
		T = T.substr(0,i);
		if(op[i]) {
			reverse(T.begin(), T.end());	
		}
	}
	
	cout << !(S.compare(T) );
}
