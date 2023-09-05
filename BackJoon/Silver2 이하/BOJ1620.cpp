#include <bits/stdc++.h>

using namespace std;

int N,M;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	map<string,string> book;
	
	cin>>N>>M;
	
	for(int i = 1 ; i<= N ; i++){
		string name;
		cin>>name;
		book[to_string(i)] = name;
		book[name] = to_string(i);
	}

	while(M--){
		string target; 
		cin>>target;
		cout<<book[target]<<"\n";
	}

}
