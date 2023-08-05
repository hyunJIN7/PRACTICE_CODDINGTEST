#include <bits/stdc++.h>
#define MAX 301
using namespace std;

int N,M;

int Combi(int n,int r){
	if (r==0 || n==r) return 1;
	return Combi(n-1,r)+Combi(n-1,r-1);
} 

int main(){
	ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin>>N>>M;
	//중복조합 nHr 을 활용 단, 모든 종류 과일 적어도 1개씩 훔쳐야함.
	cout<<  Combi(M-1,M-N);

}
