#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int K;
char condition[10];
bool used[10]={0,};
set<string> ans;
int arr[10];

void Backtrack(int arr_index){
	if(arr_index==K+1){
		string num;
		for(int i = 0 ; i < K+1 ; i++){
			num  = num + to_string(arr[i]);
		}

		ans.insert(num);
		return;
	}
	
	for(int i = 0 ; i <10 ;i++){
		bool flag = false;
		if( used[i] ) continue;
		if(!arr_index ){
			flag = true;
		}		
		else if( condition[arr_index-1]=='<'   ){
			if(arr[arr_index-1] < i ) flag=true;
			
		}
		else if (  condition[arr_index-1]=='>' ){
			if(arr[arr_index-1] > i ) flag=true;
		}
		
		if(flag){
			arr[arr_index]=i;
			used[i]=true;
			Backtrack(arr_index+1);
			used[i]=false;
		}
		
	}
	
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>K;
	for(int i = 0 ; i < K;) cin>>condition[i++];
	Backtrack(0);
	cout<< *ans.rbegin() <<endl<<  *ans.begin() ;
}
