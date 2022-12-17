//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> //for memset
#include <queue>


/*
역방향 화살표로 구성 
임의의 정점 "i" 에서 출발하여, 자신을 제외한 모든 정점에 방문할 수 있는 i를 출력하는 문제다.
이에 따라 그래프에 요소를 추가해주고, 모든 정점에서 출발할 때 마다 visited를 초기화하며
해당 조건이 가능한 i를 찾았을 때 출력하면 된다.
*/

using namespace std;
bool visited[101]={0,};
vector<int> vec[101];

void DFS(int start){

	for(int i = 0 ; i < vec[start].size(); i++){
		if(visited[vec[start][i]]) continue;
		visited[vec[start][i]]=true;
		DFS(vec[start][i]);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int N;
	cin>>N;

	for(int i = 0 ; i < N-1 ;i++){
		int from,to;
		cin>>from>>to;
		vec[to-1].push_back(from-1); // 역방향  
	}
	
	
	for(int i = 0 ; i < N-1 ; i++){
		memset(visited, 0 , sizeof(visited) );
		visited[i]=true;
		DFS(i); 
		
		if (count(visited,visited+N,1) == N){
			cout<<i+1;
			return 0;
		}
		
	}	
	
	cout<<-1;
}

