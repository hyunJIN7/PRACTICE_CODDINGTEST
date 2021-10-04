#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int arr[n],sum[n]={0,};
	for(int i = 0; i < n ;i++) cin>>arr[i];
	copy(arr,arr+n,sum);
	int ans = 0;
	for(int i = n-1; i >=0 ; i--){
		for(int j = i-1; j>=0;j--){
			if(arr[i]<arr[j]) {
				sum[j] = max(sum[i]+arr[j],sum[j]);	
			}
		}
		ans = max(ans,sum[i]);
	}
	cout<<ans;
}



