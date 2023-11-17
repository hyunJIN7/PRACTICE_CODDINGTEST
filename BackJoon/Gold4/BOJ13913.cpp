#include <bits/stdc++.h>

#define MAX 100001

using namespace std;

int N,K;

int dp[MAX] = {0,};
int prior[MAX] = {0,};//이전 원소   
queue<int> q;

bool InRange(int x){
	return 0 <= x && x < MAX;
}

void Move(int from, int to,int new_time){
	if(!InRange(to)) return;
//	cout<< from<<"-> "<<to <<" : "<<new_time<<endl;
	if( new_time < dp[to]){
		dp[to] = new_time;
		prior[to] = from;
		q.push(to);
	}
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	
	fill(dp,dp+MAX,INT_MAX);
	
	dp[N] = 0;
	prior[N] = N; 
	q.push(N);
	while(!q.empty()){
		int c = q.front();
		q.pop();
		if(c == K) break;
		Move(c, c * 2, dp[c] + 1);
		Move(c, c + 1, dp[c] + 1);
		Move(c, c - 1, dp[c] + 1);
	
	}
	
	cout<< dp[K]<<"\n";
	stack<int> s;
	s.push(K);
	for(int i = 0 ; i < dp[K]; i++){
		s.push(prior[s.top()]);
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	
}
