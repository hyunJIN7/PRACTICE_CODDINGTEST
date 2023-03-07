// 15665 backtrack ������ ���(�ߺ� ����), �̹� �������� �ߺ� �Ұ�    
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define endl "\n"
using namespace std; 

int K;
int S[13];
set<vector<int>> ans;
int arr[6];  
 
void Backtrack(int arr_index){ // arr_index : �� arr���� ���� ���� ��ġ  
	if(arr_index==6){
		//arr�� ���Ҹ� set���� �ֱ�
		vector<int> v;
		for(int i = 0 ; i <6 ; i++) 
			v.push_back(arr[i]);
		ans.insert(v);
		return;
	}
	
	for(int i = 0 ; i < K ; i++){
		if (!arr_index || arr[arr_index-1] < S[i]){ //���������� ũ�� �Ϸ���. �ߺ� ���� ����  
			arr[arr_index] = S[i];
			Backtrack(arr_index+1); 		
		}		
	}	
} 


int main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	while(1){  // �Է� cin>> �ٷ� �ؼ� while ���� �ϴ°� �ִ���  
		ans.clear();
		cin>>K;
		if(!K) return 1;	//���� �� �������� ���ٲٳ�  
		for(int i = 0 ;i < K;) cin>>S[i++];
		Backtrack(0);


		//���  
		for(auto vec: ans){
			for(int e: vec){
				cout<<e<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		
	}
}
