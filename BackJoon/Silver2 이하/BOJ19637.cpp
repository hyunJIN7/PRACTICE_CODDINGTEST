#include <iostream>
#include <algorithm> 

using namespace std;

int N,M;//������,ĳ���� �� 
vector<string> title;
vector<int> level;


/*
Ǯ�� ���� : https://github.com/devxb/JJUNalgo/blob/master/19637%20IF%EB%AC%B8%20%EC%A2%80%20%EB%8C%80%EC%8B%A0%20%EC%8D%A8%EC%A4%98/main.cpp 

lower_bound
- �̺�Ž������ Ž���ϴ� �Լ�
- ã������ key ������ ���ų� ū ���ڰ� ���� ó�� �����ϴ��� 
- ������������ ���ĵǾ� �־����. 

*/
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M;
	while(N--){
		string s; int num;
		cin >> s >>num;
		title.push_back(s);
		level.push_back(num);
	}
	
	while(M--){
		int num; cin>>num;
		cout<< title[ lower_bound(level.begin(),level.end(),num) - level.begin()] << "\n";
	}
	
} 
