//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> //for memset
#include <queue>


/*
������ ȭ��ǥ�� ���� 
������ ���� "i" ���� ����Ͽ�, �ڽ��� ������ ��� ������ �湮�� �� �ִ� i�� ����ϴ� ������.
�̿� ���� �׷����� ��Ҹ� �߰����ְ�, ��� �������� ����� �� ���� visited�� �ʱ�ȭ�ϸ�
�ش� ������ ������ i�� ã���� �� ����ϸ� �ȴ�.
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
		vec[to-1].push_back(from-1); // ������  
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

