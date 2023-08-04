#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int Q;
ll l = -1e18 ,r = 1e18;
int a1=-1,a2=-1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>Q;
	for(int i = 1 ; i <= Q ; i++){
		ll x;
		char op;
		cin>>x>>op;
		
		if(op=='^'){
			l = max(l,x+1);
		}
		else{
			r = min(r,x-1);
		}
		
		if( a2==-1 && l==r) a2 = i; 
		if(a1 == -1 && l>r) a1 = i;
	}
	
	if(l>r) cout<<"Paradox!\n"<<a1;
	else if(l==r) cout<<"I got it!\n"<<a2;
	else cout<<"Hmm...";
}
