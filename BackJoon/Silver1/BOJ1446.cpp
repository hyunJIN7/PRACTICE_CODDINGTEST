#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10010
using namespace std;

int N,D;
vector<pair<int,int>> express[MAX]; //�� ��ġ�� {����,cost} ����, 2���̰���  
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
		DP[i] = DP[i-1] + 1 ; //������ ���� ��� 
		for(int j = 0 ; j < express[i].size(); j++){// �ش� �� ��ġ(i)�� ������ ������ ���� �� ������  
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
