#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring> //memset

using namespace std;
#define MAX 100
typedef pair<int,int> pii;

int N,M;
vector<int> relation[MAX];
vector<pair<int,int>> vecAns;
bool visit[MAX]={0,};

void Input(){
	cin>>N>>M;
	while(M--){
		int a,b;
		cin>>a>>b;
		relation[a].push_back(b);
		relation[b].push_back(a);
	}
}

int Solution(int i){
	int ans=0;
	queue<pii> q;
	q.push({i,0});
	visit[i]=true;
	while(!q.empty()){
		int currentNum = q.front().first;
		int depth = q.front().second;
		q.pop();
		for(int e : relation[currentNum]){
			if(visit[e]) continue;
			q.push({e,depth+1});
			visit[e]=true;
			ans+=(depth+1);
		}
		
	}
	return ans;
	
}

void Solve(){
	Input();
	for(int i = 1 ;  i <= N; i++){
		memset(visit,0,sizeof(visit));
		vecAns.push_back( {Solution(i), i }) ;		
	}
	sort(vecAns.begin(),vecAns.end());
	cout<<vecAns[0].second;

}

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	Solve();
}
