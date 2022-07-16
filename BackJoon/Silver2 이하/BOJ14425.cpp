#include <iostream>
#include <map>
#include <string>

using namespace std;

int N,M;
map<string,int> S;
int answer = 0;

void Input(){
	cin>>N>>M;
	string s;
	while(N--){
		cin>>s;
		S[s]+=2;
	}
}

void Solution(){
	string s;
	while(M--){
		cin>>s;
		if(S[s]>1) answer++;
	}
}

void Solve(){
	Input();
	Solution();
	cout<<answer;

}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();	
}
