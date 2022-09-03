#include <iostream>
#include <stack> 

using namespace std;

int N,P;//¸á·Îµð , ÇÁ·¿ ¼ö
int result = 0; 

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	

	cin>>N>>P;
	
	stack<int> s[7];
	int line,p;
	while(cin>>line>>p){
		
//	}
//	for(int line,p; N>0 ;N--){
		
		
		if(s[line].empty() || s[line].top() < p){
			s[line].push(p);
			result++;
			continue;
		}
		if(s[line].top() == p) continue;

		while(!s[line].empty()){
			if(s[line].top() > p){
				result++;
				s[line].pop();
			}
			else break;
		}
		
		if(s[line].empty() || s[line].top() != p){
			s[line].push(p);
			result++;
		}
	}	
	cout<<result;
}
