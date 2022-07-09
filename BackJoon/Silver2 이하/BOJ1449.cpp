#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,L;
vector<int> leaks; 

void Input(){
	cin>>N>>L;
	for(int i = 0 ; i < N; i++){
		int num; cin>>num;
		leaks.push_back(num);
	}
	sort(leaks.begin(),leaks.end());
}

int Solution(){
	int ans = 0 ;
	
	int start = 0;
	for(int end=0 ;  end < N ;end++){
		if(leaks[end]-leaks[start] >= L ){
			ans++;
			start = end;
		}
	}
	return ans+1; //������ ���� ������ ���� �͵� ó���ؾ��ϱ� ����	
}

void Solve(){
	Input();
	cout<<Solution();
}

int main(){
	
	Solve();
	
}
