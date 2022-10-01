#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

int N,M;
int num[MAX];
bool visited[MAX]={0,};
set<vector<int>> answer;
int arr[MAX];

void BackTrack(int depth){
	if(depth == M){
		
		vector<int> v;
		for(int i = 0; i < M ; i++){
			v.push_back(arr[i]);
		}
		sort(v.begin(),v.end());
		answer.insert(v);
		return;
	}

	for(int i = 0 ; i < N ;i++){
		if(visited[i]) continue;
		arr[depth] = num[i];
		visited[i] = true;
		BackTrack(depth+1);
		visited[i] = false;
	}	
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i= 0; i < N ;i++)cin>>num[i];
	
	sort(num,num+N);
	
	BackTrack(0);

	for(auto v : answer){
		for(int e : v){
			cout<<e<<" ";
		}
		cout<<"\n";
	}
	
	
	
}
