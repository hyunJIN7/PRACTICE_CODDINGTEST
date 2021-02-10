// https://www.acmicpc.net/problem/11054
//{ 1 , 2 , 3 , 4 }  { 4 , 3 , 2 , 1 } -> {1 , 2 , 3 , 4 , 3 , 2 , 1} 
// ���� �κ� ���� 4 + ���� �κ� ���� 4 -1  = 7 
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,ans=0,a[1001],dp1[1001]={0,},dp2[1001]={0,};
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);	
	cin>> n;
	for(int i = 1 ;i<= n; i++){
		cin>>a[i];
		dp1[i]=1;
		//����
		for(int j = i-1 ; j>0 ; j--){
			if(a[i] > a[j] )
				dp1[i] = max(dp1[i], dp1[j]+1);
		}
	}
	
	//����, ������� 
	//���Ҵ� �迭�� ���ʿ��� �����ϴ� �κ� ������ ������ ã�Ҵ�. 
	for(int i = n; i>0 ; i--){
		dp2[i]=1;
		for(int j = i+1 ; j<=n ;j++)
			if(a[i] > a[j])
				dp2[i] = max(dp2[i], dp2[j]+1);
				
		ans = max(ans , dp1[i] + dp2[i]-1);		
	}	
	cout<<ans;
	return 0;
}

