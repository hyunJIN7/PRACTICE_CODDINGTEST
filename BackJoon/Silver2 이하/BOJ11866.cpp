#include <iostream>
#include <queue>

using namespace std;

int N,K;
string Ans = "<";

void Input(){
	cin >> N >> K;
}

void Solution(){
	queue<int> q;
	for(int i = 1; i <= N ;i++){
		q.push(i);
	}
	
	while(!q.empty()){
		if(q.size()==1){
			Ans+=(to_string(q.front()) + ">");
			return;
		}
		
		for(int j = 1; j<K;j++){
			int num = q.front();
			q.pop();
			q.push(num);
		}
		Ans +=( to_string(q.front())) + ", ";
		q.pop();
		
	}	
	
}

void Solve(){
	Input();
	Solution();
	cout<<Ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Solve();
}
