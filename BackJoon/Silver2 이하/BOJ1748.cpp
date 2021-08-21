#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	long long ans=0;
	cin >> n;
	int digit=0,tmp=n;
	while(tmp>0){
		digit++;
		tmp/=10;
	}
	

	
	for(int i =1; i < digit; i++){
		ans = ans + ((pow(10,i)-1) - pow(10,i-1) +1 ) * i  ;
	}
	ans = ans + (n - pow(10,digit-1) +1 )*digit  ;
	
	cout<<ans;
}

