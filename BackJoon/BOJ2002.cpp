///그 프로그래머스에서 완주하지 못한 선수 문제와 비슷  
// 참고 사이트 https://100100e.tistory.com/297 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N; 
	cin>>N; 
	
	unordered_map<string,int> in;
	for(int i = 0; i < N ; i++){
		string s ;
		cin>>s;
		in[s]=i;
	}
	
	
	vector<string> out(N);
	for(int i = 0 ; i < N; i++){
		cin>>out[i];
	}
	
	int ans= 0 ;
	for(int i =0 ; i < N ; i++){
		for(int j = i+1 ; j < N; j++){ // 나 이후에 나온 차 중 input 순서 먼저인 것 있다면 그건 추월 
			if(in[out[i]] > in[out[j]]){
				ans++;
				break;
			}
		}
	}
	
	cout << ans;
}
