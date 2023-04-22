#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T,N;
	cin>>T;
	
	char input[1000];
	
	while(T--){
		
		cin>>N;
		for(int i = 0 ; i < N ;)cin>>input[i++];
		
		
		
		string ans;
		ans += input[0];
		
		for(int i = 1 ; i < N ;i++){ 
			ans = ( ans[0] < input[i] )? ans+input[i] :  input[i]+ans ;		
		}
		cout<<ans<<"\n";
		
	}
	
	
}
