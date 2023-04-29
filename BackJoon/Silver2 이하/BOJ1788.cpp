#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll DIV=1000000000; 
int N; 
ll fibonacci[1000002]={0,1,0,};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	
	cin>>N;

	
	for(int i = 2 ; i <= abs(N) ; i++){
		fibonacci[i] = (fibonacci[i-2]% DIV +fibonacci[i-1]% DIV) % DIV ; 
	}
	
	if(N >0 || abs(N) % 2){
		cout<<"1\n"<<fibonacci[abs(N)];	
	}
	else if(!N){
		cout<<"0\n"<<fibonacci[abs(N)];	
	}
	else{
		cout<<"-1\n"<< fibonacci[abs(N)];	
	}
	
	
} 
