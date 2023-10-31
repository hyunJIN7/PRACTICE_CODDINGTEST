#include <bits/stdc++.h>

#define MAX_D 30

using namespace std;

int D,K;

int a[MAX_D] = {0,},b[MAX_D] = {0,};


int main(){
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cin >> D >> K;
	
	a[0] = b[1] = 1;
	for(int d = 2; d < D; d++){
		a[d] = a[d-2] + a[d-1];
		b[d] = b[d-2] + b[d-1];
	}


	for(int i = 1; i < K/2 ; i++){
		int cnt_a = a[D-1] * i;
		
		if( !((K - cnt_a) % b[D-1]) ){
			cout<< i << "\n" << (K - cnt_a) / b[D-1];
			break;
		}
	}

	return 0;	
}
