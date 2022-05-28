#include <iostream>
#include <queue>
#include <cmath> //ceil

using namespace std;

int N,M; // N : �贍� 熱, M  : 輿團 熱 
int target;//棻槭檜曖 菜ル熱;
int Ans = 0; 
priority_queue<int> pq;

void Input(){
	cin >> N;
	cin >> target;
	M+= target; 
	for(int i = 0 ; i < N-1 ; i++){
		int num; 
		cin>>num;
		pq.push(num);
		M+=num;
	}
}
// 3 0 2 2
// 4 5 7 7 7
void Solution(){
	
	while(!pq.empty()){ // target 
		if(pq.top() < target)
			break;
		
		
		int top = pq.top();		
		pq.pop();
		pq.push(top-1);
		target++;
		Ans++;
	}
	cout<<Ans;
	
}

void Solve(){
	Input();
	Solution();
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Solve();
}
