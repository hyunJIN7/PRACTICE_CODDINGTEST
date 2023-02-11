#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10010
using namespace std;

int N,D;
vector<pair<int,int>> express[MAX]; //끝 위치에 {시작,cost} 저장, 2차이거지  
int DP[MAX]={0,};
int from,to,cost;
void Input(){
	cin>>N>>D;
	for(int i = 0 ; i < N ;i++){
		cin>> from>> to >>cost;
		if( D < to || to-from <= cost) continue;
		express[to].push_back({from,cost});	
	}
}

void Solution(){
	for(int i = 1 ; i<= D ;i++){
		DP[i] = DP[i-1] + 1 ; //지름길 없는 경우 
		for(int j = 0 ; j < express[i].size(); j++){// 해당 끝 위치(i)에 지름길 여러개 있을 수 있으니  
			DP[i] = min(DP[i] , DP[express[i][j].first] + express[i][j].second);
		}
	}
	cout<<DP[D];
}

void Solve(){
	
	Input();
	Solution();
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	Solve();
}
