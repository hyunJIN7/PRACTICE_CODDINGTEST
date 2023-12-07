#include <bits/stdc++.h>

#define MAX 10
#define DIR_NUM 4
using namespace std;

int N, M, K;
vector<tuple<int,int,int>> vec;

vector<pair<int,int>> selected;

int answer = INT_MIN;

int dy[DIR_NUM] = {0,0,1,-1};
int dx[DIR_NUM] = {1,-1,0,0};

bool CanGo(pair<int,int> pos){
	for(int i = 0 ; i < selected.size(); i++){
		int y,x;
		tie(y,x) = selected[i];
		for(int d = 0 ; d  < DIR_NUM; d++){
			int ty = y + dy[d], tx = x + dx[d];
			if(make_pair(ty,tx) == pos) return false;
		}
	}
	return true;
}

void FindCombination(int depth,int start,int sum){
	if(depth == K){
		answer = max(answer,sum);
		return;
	}
	
	for(int i = start + 1; i < N*M; i++){
		int num,y,x;
		tie(num,y,x) = vec[i];
		if(!CanGo({y,x})) continue;
		selected.push_back({y,x});
		FindCombination(depth + 1, i, sum + num);
		selected.pop_back();
	}
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;
	for(int i = 0,num ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			cin >> num;
			vec.push_back(make_tuple(num,i,j));
		}
	}
	sort(vec.begin(),vec.end());
	FindCombination(0,-1,0);
	
	cout<<answer;
	
}
