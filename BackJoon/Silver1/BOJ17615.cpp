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
	//���ʿ� R ������
	while(input[id++]=='R'){cnt++;} //���ʿ��� ���������� �ִ� R ī��Ʈ  
	minN = min(minN,Rcnt-cnt); 
	//�����ʿ� R ������
	id=N-1,cnt=0;
	while(input[id--]=='R'){cnt++;}
	minN = min(minN,Rcnt-cnt); 
	
	//���ʿ� B ������
	id=0,cnt=0;
	while(input[id++]=='B'){cnt++;}
	minN = min(minN,Bcnt-cnt); 
	
	//�����ʿ� B ������
	id=N-1,cnt=0;
	while(input[id--]=='B'){cnt++;}
	minN = min(minN,Bcnt-cnt); 
	
	cout<<minN; 

}
