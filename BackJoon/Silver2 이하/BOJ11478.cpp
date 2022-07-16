#include <iostream>
#include <map>
#include <string>

using namespace std;

string S;
map<string,int> m;

void Input(){
	cin>>S;
}

void Solution(){
	for(int i = 0 ; i < S.length();i++){
		for(int j = 1 ; j <= S.length()-i ;j++){
			m[S.substr(i,j)]++;
		}
	}
}

void Solve(){
	Input();
	Solution();
	cout<<m.size();
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	Solve();	
}
