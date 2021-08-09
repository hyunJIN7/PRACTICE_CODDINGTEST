#include <bits/stdc++.h>
using namespace std;
vector<int> v[101];
bool visited[101]={0,};
int ans=0;
void BFS(){
	queue<int> q;
	q.push(1);
	visited[1]=true;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int e : v[node]){
//			cout<<e<<"\n";
			if(!visited[e]){
				q.push(e);
				visited[e]=true;
				ans++;
			}
		}
	}
	
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,t;
	cin >> n>> t;
	while(t--){
		int f,t;
		cin>>f>>t;
		v[f].push_back(t);
		v[t].push_back(f);
	}	
	BFS();
	cout<<ans;
}
