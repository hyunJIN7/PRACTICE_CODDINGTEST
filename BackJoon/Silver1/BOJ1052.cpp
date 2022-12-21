//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N,K;
int ans=0;

int BinaryCount(int n){
	int cnt = 0;
	
	for(int i = 0 ;  n != 0 ; i++){
		n = n & (n-1);
		
		cnt++;
	}
	
	return cnt;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>N>>K;

//	int add = N&(-N);
//	ans+= add;
//	N+= add;
//	cout<<add;


	while(1){
		if (BinaryCount(N)<=K){
			cout<<ans;
			return 0;
		}
		else{
			int add = N&(-N);
			ans+= add;
			N+= add;
			
//			cout<<add<<"\n";
		}
		
	}
		
}
