#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	vector<pair<int,int>> v;
	int arr[51][3]={0,};
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i][0]>>arr[i][1];
	}
	string ans;
	for(int i = 0; i <n ;i++){
		
		for(int j = 0 ; j < n ;j ++){
			if(j==i) continue;
			
			if(arr[i][0] < arr[j][0] and arr[i][1] < arr[j][1]) arr[i][2]++;
			
		}
		ans = ans + to_string(arr[i][2]+1) +" ";
	}
	cout<<ans;
	
}

