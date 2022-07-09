#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric> // accumulate

using namespace std;
typedef long long ll;

int N,M; //카드 수, 세트 수 
priority_queue<ll,vector<ll>, greater<ll> > cards;

void Input(){
	cin>>N>>M;
	for(int i = 0; i < N ;i++){
		ll num;
		cin>>num;
		cards.push(num);
	}
}

void Solution(){
	while(M--){
		ll newNum = cards.top();
		cards.pop();
		newNum += cards.top();
		cards.pop();
		cards.push(newNum);
		cards.push(newNum);
	}	
}

void Solve(){
	Input();
	Solution();
	ll ans = 0;
	while(!cards.empty()){
		ans+=cards.top();
		cards.pop();
	}
	cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	Solve();
	
}
