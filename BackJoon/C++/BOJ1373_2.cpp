#include <bits/stdc++.h>
using namespace std;
int main(){
	string n,ans;
	cin>>n;
	int len = n.size();
	if( len %3 == 1)
		cout<<n[0]; // ���� -'0' �ʿ� ���� �״�� ��� �������� ���� ������ 
	else if(len%3==2) cout <<( n[0] -'0')*2 + (n[1] -'0') ;
	for(int i = len%3 ; i < len ; i+=3 )
		cout << ( n[i]-'0') * 4 + (n[i+1]-'0')*2 + (n[i+2] -'0');
	return 0;
}
