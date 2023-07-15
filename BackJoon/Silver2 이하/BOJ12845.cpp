#include <bits/stdc++.h> 

using namespace std; 

int N,ans=0;
int level[1001];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0 ; i < N ; i++){
		cin>>level[i];
		ans+= level[i];
	} 
	int maxN = *max_element(level,level+N);
	ans-= maxN;
	ans = ans + maxN*(N-1) ;
	cout<<ans;
}
