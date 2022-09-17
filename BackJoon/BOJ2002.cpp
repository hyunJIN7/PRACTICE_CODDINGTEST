///�� ���α׷��ӽ����� �������� ���� ���� ������ ���  
// ���� ����Ʈ https://100100e.tistory.com/297 
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
		for(int j = i+1 ; j < N; j++){ // �� ���Ŀ� ���� �� �� input ���� ������ �� �ִٸ� �װ� �߿� 
			if(in[out[i]] > in[out[j]]){
				ans++;
				break;
			}
		}
	}
	
	cout << ans;
}
