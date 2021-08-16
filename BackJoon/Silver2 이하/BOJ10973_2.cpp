#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string ans;
	int n;
	int num[n+1];
	cin >>n;

	for(int i = 0 ; i < n ; i++) {	cin >> num[i];}	

	if(prev_permutation(num,num+n)){ // 이전 순열이 있다면 true반환  
		for(int i = 0 ; i < n; i++){
			cout<<num[i]<<" ";
		}
	}
	else cout<<"-1";
	
}
