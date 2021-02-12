//https://www.acmicpc.net/problem/9012 
#include <bits/stdc++.h>
using namespace std;

int main(){
	//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	string s;
	cin >>N;
	while(N--){
		cin>>s;
		stack<char> stack; //stack ��� �׳� int ���� �ϳ� �ΰ� ++--�ص��ɵ�  
		for(char c : s){
			if(c == '(')	stack.push('(');				
			else{ //  ) 
				if(stack.empty()){
					stack.push('(');
					break;
				}
				stack.pop();
			}
		}
	 	(stack.empty() )?(cout<<"YES\n") : (cout<<"NO\n");
	}
	return 0;
}

