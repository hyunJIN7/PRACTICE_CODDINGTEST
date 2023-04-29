#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int A,B,N,M;
	cin>>A>>B>>N>>M;
	
	
	multimap<int,int> mMap;
	for(int i = 0 ; i < M ; i++){
		int from,to;
		cin>>from>>to;
		mMap.insert({from,to});
		mMap.insert({to,from});
	}

	bool visited[1002]={0,};
	queue<pair<int,int>> que;
	que.push({A,0});
	visited[A]=true;
	while(!que.empty()){
		int curr = que.front().first;
		int depth = que.front().second;
		que.pop();
		if(curr == B){
			cout<<depth;
			return 0;
		}
		
		for(auto it = mMap.lower_bound(curr); it!=mMap.upper_bound(curr); it++){
			if(!visited[it->second]){
				que.push({it->second,depth+1});	
				visited[it->second]=true;
				
			} 
		}
	}
	
	cout<<-1;
}
