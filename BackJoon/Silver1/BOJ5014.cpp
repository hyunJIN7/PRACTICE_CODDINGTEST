#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int F,S,G,U,D;
bool visited[MAX]={0,};
int bnt[MAX]={0,};
int dx[2]={0,};
void BFS(){
	queue<int> que;
	que.push(S);
	visited[S]=true;
	
	while(!que.empty()){
		int currX = que.front();
		que.pop();
		
		
		
		for(int i = 0 ; i < 2 ; i++){
			int newX = currX + dx[i];
			if(newX <= 0 || newX > F) continue;
			if(visited[newX])  continue;
			
			que.push(newX);
			visited[newX]=true;
			bnt[newX] = bnt[currX]+1;
			
//			cout<<currX <<"->"<<newX<<" : "<< bnt[newX]<<endl;

		}
		
	}
	
	
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>F>>S>>G>>dx[0]>>dx[1];
	dx[1]*=-1;

	if(G==S){
		cout<<"0";
		return 0;
	} 
	BFS();

	(bnt[G])? cout<< bnt[G] :  cout<< "use the stairs" ;

}
