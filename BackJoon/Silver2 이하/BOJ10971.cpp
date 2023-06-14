#include <bits/stdc++.h>
#define Fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 11

using namespace std;

int N;
int arrbridge[MAX][MAX];
int ans = 0x7f7f7f7f;
bool visited[MAX]={0,};
int start;
void Backtrack(int from,int to, int index, int weight){
	if(visited[to] || index >= N ) return;
	if(!arrbridge[from][to] && from!=to) return;	
	visited[to] = true;
	int newWeight = weight + arrbridge[from][to];
	
	

//	cout<< from << " -> " << to <<" weight sum : "<< newWeight<<endl;
	
	if(index==N-1){// 다 순회했으면 
		if(arrbridge[to][start]){
			newWeight +=arrbridge[to][start];
			ans = (newWeight < ans) ? newWeight : ans; //시작점으로 돌아갈 수 있으면 	
//			cout<<"===== "<< ans<<"========\n";
		}		
		return; 
	}
	
	
	for(int i = 0 ; i < N ;i++){
		if(!visited[i]){
			Backtrack(to,i,index+1,newWeight);	
			visited[i]=false;
		}
		
	}
		
}

int main(){
	Fastio;
	cin>>N;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
		 cin>>arrbridge[i][j];
		}
	}

	
	for(int i = 0 ; i < N ;i++){
		start = i;
		Backtrack(i,i,0,0);
	}
	
	cout<<ans;
	
}
