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
	//�ߺ����� nHr �� Ȱ�� ��, ��� ���� ���� ��� 1���� ���ľ���.
	cout<<  Combi(M-1,M-N);

}
