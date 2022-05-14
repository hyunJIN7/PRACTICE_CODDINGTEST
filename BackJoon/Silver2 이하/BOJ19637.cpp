#include <iostream>
#include <algorithm> 

using namespace std;

int N,M;//레벨수,캐릭터 수 
vector<string> title;
vector<int> level;


/*
풀이 참고 : https://github.com/devxb/JJUNalgo/blob/master/19637%20IF%EB%AC%B8%20%EC%A2%80%20%EB%8C%80%EC%8B%A0%20%EC%8D%A8%EC%A4%98/main.cpp 

lower_bound
- 이분탐색으로 탐색하는 함수
- 찾으려는 key 값보다 같거나 큰 숫자가 언제 처음 등장하는지 
- 오름차순으로 졍렬되어 있어야함. 

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
