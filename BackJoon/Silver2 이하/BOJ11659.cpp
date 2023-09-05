#include <bits/stdc++.h>

using namespace std;

int arr[1000001]={0,};
int N,M;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>N>>M;
	for(int i = 1; i <= N ; i++){
		cin>>arr[i];
		arr[i] += arr[i-1];
	} 
	while(M--){
		int s,e;
		cin>>s>>e;
		cout<<arr[e]-arr[s-1]<<"\n";
	}
	
}
