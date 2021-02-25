#include <bits/stdc++.h>

using namespace std;
vector<int> city[300001]; // N
bool visited[300001]={0,};
int n,m,k,x;
vector <int> ans;

void bfs(){ // ��� x , ��ǥ �Ÿ� k 
	queue<pair<int,int>> q;
	q.push({x,0});
	visited[x] = true;
	while(!q.empty()){
		int node = q.front().first;
		int dist = q.front().second;
		q.pop();
		if(dist == k){
			ans.push_back(node);
		}
		
		for(int e : city[node]){
			if(!visited[e]){
				q.push({e, dist+1});
				visited[e] = true;
			}
		}
		
	}	
	
	
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>> n>>m>>k>>x;//���ð���,���μ�,�Ÿ�,���۵��� 
	while(m--){
		int u,v;
		cin>>u>>v;
		city[u].push_back(v);	
	}
	bfs();
	if(ans.size() == 0){
		cout<<-1; return 0;
	}
	sort(ans.begin(),ans.end());
	for(int e:ans) cout<<e<<"\n";
	return 0;
} 
