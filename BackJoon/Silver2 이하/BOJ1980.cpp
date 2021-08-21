#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,t,tmp;
	cin >>n>>m>>t;
	
	tmp = n+m;
	n = min(n,m);
	m = tmp-n;
	
	int ans[2]={0,100000};
	for(int i = t/n; i>=0 ;i--){// i가 시간 적은 햄버거 개수  
		int j = (t-n*i)/m; // 다른 햄버거 개수 
		int ham_cnt = i + j;
		int coke_time = t - n * i - m * j;
		
		if( coke_time < ans[1] ){ //기존보다 coke 짧아
			ans[0] = ham_cnt ;
			ans[1] = coke_time;
		}	
		else if( coke_time == ans[1] && ham_cnt > ans[0] ){
			ans[0] = ham_cnt ;
		}
	}
	cout<< ans[0]<<" "<<ans[1];
	
	
}

