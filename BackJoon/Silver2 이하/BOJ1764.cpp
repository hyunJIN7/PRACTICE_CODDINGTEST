/*
	�赵, ���� ������ �ʰ� �ѹ��� �Է� �޾Ƽ� ������ ī��Ʈ �� �͵� ��� 
	�ڷᱸ���� map����, ���� �� ������ �ʿ��ϱ� ������  
*/

#include<iostream>
#include<map>

using namespace std;
map<string, int> m;

void Input(){
	int N,M; 
	cin >>N>>M; 
	N = N+M;
	for(int i=0 ; i < N ; i ++){
		string name; cin>>name;
		m[name]++;
	}
}

void Solution(){
	int cnt = 0;
	string ans;
	for(auto it : m){

		if(it.second > 1 ){
			cnt++;
			ans+=it.first+"\n";
		} 	
	}
	cout<<cnt<<"\n"<<ans;
}

void Solve(){
	Input();
	Solution();
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Solve();
}
