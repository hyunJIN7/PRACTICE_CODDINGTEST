#include <bits/stdc++.h>

#define MAX 100001 

using namespace std;

int N,K;
int arrival_time[MAX];


void Solve(){
	cin >> N >> K;
	
	fill(arrival_time,arrival_time + MAX, INT_MAX);
	
	queue<int> q;
	q.push(N);
	arrival_time[N] = 0;	
	while(!q.empty()){
		int curr_p = q.front();
		q.pop();
		
		for(int i = - 1; i <= 1 ; i++){
			int next_p = curr_p, next_t = arrival_time[curr_p];
			if(!i)  // 순간 이동  
				next_p += curr_p;	
			else{
				next_p += i;
				next_t++;
			}
			if(next_p < 0 || next_p >= MAX) continue;
			if(next_t < arrival_time[next_p]){
				arrival_time[next_p] = next_t;
				q.push(next_p);
			}
			
		}
		
	}

	cout << arrival_time[K];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	Solve();
	return 0;	
}
