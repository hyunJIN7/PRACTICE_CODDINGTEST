// 15665 backtrack 문제와 비슷(중복 가능), 이번 문제에선 중복 불가    
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
 
void Backtrack(int arr_index){ // arr_index : 는 arr에서 새로 넣을 위치  
	if(arr_index==6){
		//arr의 원소를 set으로 넣기
		vector<int> v;
		for(int i = 0 ; i <6 ; i++) 
			v.push_back(arr[i]);
		ans.insert(v);
		return;
	}
	
	for(int i = 0 ; i < K ; i++){
		if (!arr_index || arr[arr_index-1] < S[i]){ //이전수보다 크게 하려고. 중복 제거 위해  
			arr[arr_index] = S[i];
			Backtrack(arr_index+1); 		
		}		
	}	
} 


int main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	while(1){  // 입력 cin>> 바로 해서 while 조건 하는거 있던데  
		ans.clear();
		cin>>K;
		if(!K) return 1;	//여기 좀 간지나게 못바꾸나  
		for(int i = 0 ;i < K;) cin>>S[i++];
		Backtrack(0);


		//출력  
		for(auto vec: ans){
			for(int e: vec){
				cout<<e<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		
	}
}
