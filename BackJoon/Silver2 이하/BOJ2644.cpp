#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 101
typedef pair<int,int> pii;

int N,M; //N 전체 사람 수,  
int tagetA,targetB;
int Ans=-1;
vector<int> relation[MAX];
bool visit[MAX]={0,};


void Input(){
	cin>>N;
	cin>>tagetA>>targetB;
	cin>>M;
	while(M--){
		int a,b;
		cin>>a>>b;
		relation[a].push_back(b);
		relation[b].push_back(a);
	}
}

int Solution(){
	queue<pii> que;
	que.push({tagetA,0});
	visit[tagetA] = true;
	
	while(!que.empty()){
		int currentNum = que.front().first;
		int currentDepth = que.front().second;
		que.pop();
		for(auto e : relation[currentNum]){
			if(visit[e]) continue;
			
			if(e == targetB) return currentDepth+1;
			
			que.push({e,currentDepth+1});
			visit[e]=true;
		}	
	}
	return -1;
}

void Solve(){
	Input();
	cout<<Solution();
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Solve();
	
}
