#include <bits/stdc++.h>
using namespace std;
int n,max_cnt=0;
int arr[500001];
map<int,int> m;
int avg=0;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
		avg+=arr[i];
		
		if(m[arr[i]]) m[arr[i]]++;
		else m[arr[i]]=1;
		max_cnt = max(m[arr[i]], max_cnt);
	}
	sort(arr,arr+n);

	//1
	cout <<round((double)avg/(double)n )<<"\n";
	//2
	cout << arr[n/2]<<"\n";

	//3
	vector<int> v;
	for(auto e:m){
		if(max_cnt == e.second) v.push_back(e.first);
	}
	sort(v.begin(),v.end());
	v.size()==1? cout <<v[0]<< "\n" : cout <<v[1] << "\n";
		
	//4
	cout<<arr[n-1]-arr[0];
	
	
}
