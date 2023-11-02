#include <bits/stdc++.h>

#define MAX 2000

using namespace std;

int N, M;
vector<int> relation[MAX];

bool visited[MAX] = {0,};
int arr[MAX]; 

int ans = 0;

void Input(){
	cin >> N >> M;
	while(M--){
		int from, to;
		cin >> from >> to;
		relation[from].push_back(to);
		relation[to].push_back(from);
		
	}
}

void Backtrack(int num,int depth){	
	if(depth == 5){
		ans = 1;
		return;
	}
	for(int r : relation[num]){
		if(visited[r]) continue;
		visited[r] = true;
		arr[depth] = r;
		Backtrack(r,depth+1);
		visited[r] = false;
	}
	
}

void Solve(){
	Input();	
	
	for(int i = 0 ; i < N ; i++){
		arr[0] = i;
		visited[i] = true;
		Backtrack(i,1);
		visited[i] = false;
		
		if(ans) break;
	}
	cout << ans;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	Solve();
	return 0;	
}
