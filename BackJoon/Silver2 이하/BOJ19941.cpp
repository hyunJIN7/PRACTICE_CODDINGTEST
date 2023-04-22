#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int N,K,ans=0;
	cin>>N>>K;
	
	char input[N];
	for(int i = 0 ; i < N ; i++) {
		cin>>input[i];	
	}
	
	for(int i = 0 ; i < N ; i++) {
		if(input[i] !='P') continue;
		
		for(int j = -K ; j <= K ;j++){
			if(i+j < 0 || i+j >= N) continue;
			if(input[i+j]== 'H'){
				ans++;
				input[i+j] = '0';
				break;
			} 
			
		}
			
	}	
	cout<<ans;
	
} 
