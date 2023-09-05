#include <bits/stdc++.h>

using namespace std;

int arr[100][100]={0,};
int N;
vector<int> link[100];

void Input(){
	cin>>N;
	for(int i = 0,num ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin>>num;
			if(num) link[i].push_back(j);
		}	
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	Input();
	
	for(int i = 0  ; i < N ; i++){
		bool visited[100]={0,};
		queue<int> que;
		que.push(i); //넣을때 true하고 그래야 돌 수 있어.  
		while(!que.empty()){
			int num = que.front();
			visited[num];
			que.pop();
			for(auto e : link[num]){
				if(visited[e]) continue;
				visited[e] = true;
				que.push(e);
				arr[i][e]=1;
			}
		}
		
	}
	
	for(int i = 0,num ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout<<arr[i][j]<<" ";
		}	
		cout<<"\n";
	}
	
}
