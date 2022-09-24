//참고 사이트 https://tooo1.tistory.com/327 
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;


int N,M;
int num[MAX]; //input 
bool visited[MAX]={0,};
int arr[MAX];
set<vector<int>> s;

void Backtrack(int depth){//depth : depth이자 arr의 index 
	if(depth == M){
		vector<int> v;
		for(auto i = 0; i<M;i++) v.push_back(arr[i]);
		s.insert(v);		
		return;
	}
	
	for(int i = 0 ; i < N ;i++){
		if(visited[i]) continue;
		visited[i] = true;
		arr[depth] = num[i];
		Backtrack(depth+1);
		visited[i]=false;
	}	
}
 

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i = 0 ; i<N; i++) cin>>num[i];
	sort(num,num+N);
	Backtrack(0);//depth 의미
	for(auto v : s){
		for(auto e : v){
			cout<<e<<" ";
		}
		cout<<"\n";
	}  

	
}
