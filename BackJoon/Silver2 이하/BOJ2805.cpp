#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N,M; 
ll tree[1000001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i = 0 ; i < N; i++) cin>>tree[i];
	sort(tree,tree+N);

	ll start=0,end=0;
	end = tree[N-1];

	ll maxHeight = 0;
	while(start < end){
		
		ll mid = (start + end)/2;
		ll cnt = 0;
		
		for(auto e : tree){
			cnt += (mid < e)?  e - mid : 0;
		}
		
		if(cnt < M){
			end = mid;
		}else{
			start=mid+1;
			maxHeight = (maxHeight < mid)? mid : maxHeight;		
		}
		
	}
	cout<<maxHeight;
	
}



