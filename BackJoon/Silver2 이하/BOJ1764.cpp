/*
	듣도, 보도 나누지 않고 한번에 입력 받아서 여러번 카운트 된 것들 출력 
	자료구조는 map으로, 사전 순 정렬이 필요하기 때문에  
*/

#include<iostream>
#include<map>

using namespace std;
map<string, int> m;

void Input(){
	int N,M; 
	cin >>N>>M; 
	N = N+M;
	for(int i=0 ; i < N ; i ++){
		string name; cin>>name;
		m[name]++;
	}
}

void Solution(){
	int cnt = 0;
	string ans;
	for(auto it : m){

		if(it.second > 1 ){
			cnt++;
			ans+=it.first+"\n";
		} 	
	}
	cout<<cnt<<"\n"<<ans;
}

void Solve(){
	Input();
	Solution();
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Solve();
}
