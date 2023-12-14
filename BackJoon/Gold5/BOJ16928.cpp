#include <bits/stdc++.h>

#define MAX 101

using namespace std;

int N,M;
int dp[MAX] = {0,};
int jump[MAX] = {0,}; // »ç´Ù¸®¿Í ¹ì  

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> N >> M;
	for(int i = 0 ; i < N + M; i++){
		int from,to;
		cin >> from >> to;
		jump[from] = to;
	}
	queue<int> que;
	que.push(1);
	dp[1] = 1;

	while(!que.empty()){
		int curr_pos = que.front();
		que.pop();
		
		for(int i = 1 ; i <= 6; i++){
			int next_pos = curr_pos + i;
			if(next_pos > 100 ) continue;
			if(next_pos == 100){
				cout << dp[curr_pos];
				return 0;
			}
			int jump_pos = jump[next_pos]? jump[next_pos]: next_pos;
			if(dp[jump_pos]) continue;
			dp[jump_pos]  = dp[curr_pos] + 1;
			que.push(jump_pos);
		} 	
	}

	return 0;
}
