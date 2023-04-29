#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N;
	multimap<int,int> mMap;
	cin>>N;
	for(int i = 1 ; i < N ; i++){
		int num;
		cin>>num;
		for(int j = 1 ; j <= num ; j++){
			mMap.insert({i,i+j});
		}
	}
	int tmp; cin>>tmp;//버리기 
	
	bool visited[1010]={0,};
	queue<pair<int,int>> que;//위치,jump cnt
	que.push({1,0});
	visited[1]=true;
	while(!que.empty()){
		int curr = que.front().first;
		int jump = que.front().second;
		que.pop();
		
		if(curr == N){
			cout<<jump;
			return 0;
		}
		
		for(auto it = mMap.lower_bound(curr); it != mMap.upper_bound(curr); it++){
			if(!visited[it->second]){
				que.push({it->second,jump+1});
				visited[it->second]=true;
			}
			
		}
		
		
	} 
	cout<<-1;
	
}
