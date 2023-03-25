#include <iostream>
#include <queue>
#include <set>

#define MAX 100010
using namespace std;

int N,M,R;
int ans[MAX]={0,};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>R;
	
	set<int> S[N+1];
	for(int i = 0,u,v ; i < M ; i++){
		cin>>u>>v;
		S[u].insert(v);
		S[v].insert(u);
	}
	
	
	queue<int> Q;
	Q.push(R);
	int order=1;
//	ans[R]=order++;
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		ans[curr] = order++;
		
		for(auto e : S[curr]){
			if(!ans[e]){
				Q.push(e);
//				ans[e]=order++;
			}
		}
	}
	for(int i = 1 ; i <=N ; i++){
		cout<<ans[i]<<"\n";
	}
	
}
