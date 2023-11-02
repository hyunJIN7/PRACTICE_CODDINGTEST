#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

/*
 T -> S �������� 
 ���� T[i]�� A��� 
 S[i-1] -> S[i] : A�߰�, �̷��� ������ ��������.  
*/


int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	string S,T;
	cin >> S >> T;
	int Slen = S.size(),Tlen = T.size();
	
	int op[MAX]; // index : s ~ Tlen-1 ����   
	
	//� ���� �ؾ��ϴ���  	
	// �ش� ���꿡 �°� �ٲ㼭 T�� ���� Ȯ��	 
	for(int i = Tlen - 1 ; Slen <= i; i--){
		op[i] = (T[i] == 'A')? 0 : 1;		
		T = T.substr(0,i);
		if(op[i]) {
			reverse(T.begin(), T.end());	
		}
	}
	
	cout << !(S.compare(T) );
}
