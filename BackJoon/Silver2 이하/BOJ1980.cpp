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
	for(int i = t/n; i>=0 ;i--){// i�� �ð� ���� �ܹ��� ����  
		int j = (t-n*i)/m; // �ٸ� �ܹ��� ���� 
		int ham_cnt = i + j;
		int coke_time = t - n * i - m * j;
		
		if( coke_time < ans[1] ){ //�������� coke ª��
			ans[0] = ham_cnt ;
			ans[1] = coke_time;
		}	
		else if( coke_time == ans[1] && ham_cnt > ans[0] ){
			ans[0] = ham_cnt ;
		}
	}
	cout<< ans[0]<<" "<<ans[1];
	
	
}

