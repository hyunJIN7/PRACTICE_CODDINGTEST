#include <bits/stdc++.h>
using namespace std;
int main(){
	string w;
	cin>>w;
// �⺻ Ǯ��
//	int a[26]; 
//	memset(a,-1,sizeof(a));
//	for(int i = -1; w[++i] ;) 
//		if(a[w[i]-'a'] < 0) 
//			a[w[i]-'a'] = i;
//	for(auto e : a) cout<<e<<" ";

// find Ȱ���ؼ� �ѹ��� ����!!! 
	for(char c = 'a'; c<='z';c++) cout<<int(w.find(c))<<" ";
	return 0;
} 
