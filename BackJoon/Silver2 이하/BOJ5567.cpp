#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N,M,ans=0;
bool visited[501]={0,};
vector<int> graph[501];


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	while(M--){
		int from,to;
		cin>>from>>to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	//BFS
	
	queue<pair<int,int>> q;
	q.push({1,0});
	visited[1]=true;
	while(!q.empty()){
		int target = q.front().first; 
		int dpeth = q.front().second;
		q.pop();
		
		if(dpeth <= 2) ans++;
		
		for(int e : graph[target]){
			if(visited[e]) continue;
			visited[e] = true;
			q.push({e,dpeth+1});
		}
		
	}
	cout<<ans-1; // 1¹ø Æ÷ÇÔÇÏ´Â °ªÀÌ¶ó »©ÁÜ  
}
