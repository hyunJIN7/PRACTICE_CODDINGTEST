#include <bits/stdc++.h> 

using namespace std; 

int N,ans=0;
int snow[101];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0 ; i < N ; i++){
		cin>>snow[i];
		if(snow[i]>1440){
			cout<<-1;
			return 0;
		}
		if(N==1){
			cout<<snow[i];
			return 0;
		}
	}
	
	sort(snow,snow+N);
	while(snow[N-1]){
		snow[N-1]--;
		if(snow[N-2])snow[N-2]--;
		ans++;
		sort(snow,snow+N);
	}
	
	cout<<ans;
	
}
