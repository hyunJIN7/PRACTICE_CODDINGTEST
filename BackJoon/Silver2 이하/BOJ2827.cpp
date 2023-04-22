#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int N;
	cin>>N;
	
	vector<int> arr(N);
	for(int i = 0 ; i < N ; i++) cin>>arr[i];
	
	int ans = N;
	for(int i = N-1; i>=0 ; i--){
		if(arr[i] == ans) ans--;
	}
	cout<<ans;
	
	
}

