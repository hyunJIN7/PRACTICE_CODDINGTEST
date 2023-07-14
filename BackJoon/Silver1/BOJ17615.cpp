#include <bits/stdc++.h> 
#define MAX 500010
using namespace std; 

int N,Rcnt=0,Bcnt=0;
string input;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>input;
	for(auto e : input){
		if(e == 'R') Rcnt++;
		else Bcnt++;
	}
	
	int minN=MAX,cnt=0,id=0;
	//왼쪽에 R 모으기
	while(input[id++]=='R'){cnt++;} //왼쪽에서 연속적으로 있는 R 카운트  
	minN = min(minN,Rcnt-cnt); 
	//오른쪽에 R 모으기
	id=N-1,cnt=0;
	while(input[id--]=='R'){cnt++;}
	minN = min(minN,Rcnt-cnt); 
	
	//왼쪽에 B 모으기
	id=0,cnt=0;
	while(input[id++]=='B'){cnt++;}
	minN = min(minN,Bcnt-cnt); 
	
	//오른쪽에 B 모으기
	id=N-1,cnt=0;
	while(input[id--]=='B'){cnt++;}
	minN = min(minN,Bcnt-cnt); 
	
	cout<<minN; 

}
