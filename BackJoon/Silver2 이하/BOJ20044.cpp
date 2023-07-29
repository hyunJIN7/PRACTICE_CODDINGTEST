#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> vec;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0 ; i < 2*N; i++){
		int num;
		cin>>num;
		vec.push_back(num);
	}
	
	sort(vec.begin(),vec.end());
	int ans = 5000*2;
	
	for(int i ; i < N ; i++){
		int candi = vec[i] + vec[2*N - 1 - i];
		ans = (candi <ans)? candi : ans ;
	}
	
	cout<<ans;
}
