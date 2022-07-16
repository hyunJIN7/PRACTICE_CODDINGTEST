#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int testcaseNum;
int answer;
map<string,int> hm;

void Input(){
	int n;
	cin>>n;
	
	string key,value;
	while(n--){
		cin>>value>>key;		
		hm[key]++;
	}
}

void Solution(){
	answer = 1;
	for(auto i : hm){
		answer *= (i.second+1);
	}
	answer--;
}

void Solve(){
	answer= 0;
	Input();
	Solution();
	cout<<answer<<"\n";
	
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>testcaseNum;
	while(testcaseNum--){
		hm.clear();
		Solve();		
	}	
}
