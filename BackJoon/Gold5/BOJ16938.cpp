#include <bits/stdc++.h>

#define MAX_N 15
#define MAX_LEVEL 1000000

using namespace std;
			
int N,L,R,X;
int level[MAX_N];
bool visited[MAX_N] = {0,};
int ans = 0;

void Backtrack(int start, int sum, int min_level, int max_level, int depth){
	// 시작 인덱스, 전체 합, 원소 min,max, 원소 개수  
	if(depth >= 2 ){
		if(sum > R || depth > N) return;
		else if(sum >= L)
			if(min_level + X <= max_level)
				ans++;	
	}
	
	for(int i = start + 1 ; i < N ; i++){
		if(visited[i]) continue;
		visited[i] = true;
		Backtrack(i,sum + level[i],min(min_level, level[i]),max(max_level, level[i]), depth +1);
		visited[i] = false;		
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> L >> R >> X;
	for(int i = 0 ; i < N ; i++) cin >> level[i];
	
	Backtrack(-1,0,MAX_LEVEL,0,0);
	cout << ans; 
	
	return 0;	
}
