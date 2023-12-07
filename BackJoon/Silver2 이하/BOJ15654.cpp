#include <bits/stdc++.h>
#define MAX 8
using namespace std;

int N,M;
int input[MAX]; 

bool visited[MAX];
int num[MAX];

set<vector<int>> answer;

void Backtrack(int depth){
	if(depth == M){
		vector<int> vec;
		for(int i = 0 ; i < M; i++){
			vec.push_back(num[i]);
//			cout<< num[i]<<" ";	
		} 
		answer.insert(vec);
	}
	
	for(int i = 0 ; i < N ; i++){
		if(visited[i]) continue;
		visited[i] = true;
		num[depth] = input[i];
		Backtrack(depth + 1);
		visited[i] = false;
	}

}

void print_answer(vector<int> vec){
	for(int i = 0 ; i < M ; i++)
		cout<< vec[i]<<" ";
	cout<<"\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for(int i = 0 ; i < N ; i++) cin >> input[i];
	
	Backtrack(0);
	for_each(answer.begin(),answer.end(),print_answer);
	
}
