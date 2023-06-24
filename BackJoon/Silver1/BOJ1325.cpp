#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;


const int MAX = 10001;
bool visited[MAX]={0,};
int N,M;
vector<int> confi[MAX];

int BFS(int num){
	int cnt=0;
	visited[num] = true;
	queue<int> que;
	que.push(num);
	while(!que.empty()){
		int from = que.front();
		que.pop();
		cnt++;
		for(auto e : confi[from]){
			if(!visited[e]){
				que.push(e);
				visited[e] = true;
			}
		}
	}
	
	return cnt;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a,b;
		cin>>a>>b;
		confi[b].push_back(a);
	}
	
	
	int maxCnt=0;
	vector<int> ans;
	
	for(int i = 1 ; i <= N ;i++){
		memset(visited,0,sizeof(visited));
		int cnt = BFS(i);

		if(cnt > maxCnt){
			ans.clear();
			maxCnt = cnt;
		}
		
		if(cnt == maxCnt){
			ans.push_back(i);	
		}	
		
	}
	
	sort(ans.begin(),ans.end());
	for(auto e : ans){
		cout<<e<<" ";
		
	}
	
	
}
