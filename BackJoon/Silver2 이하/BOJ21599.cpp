#include <bits/stdc++.h>
#define MAX  0x7f7f7f7f
using namespace std;

int N;
int cnt[500005]={0,};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>N;
	for(int i = 1 ; i <= N ;i++){
		cin>>cnt[i];
	}

	sort(cnt+1,cnt+N+1,greater<int>());

	for(int i = 1 ; i <= N ; i++){
		cnt[i] = (cnt[i-1]-1 < cnt[i]) ? cnt[i] : cnt[i-1]-1;	
		if(!cnt[i]){
			cout<<i-1;
			return 0;
		}
	}
	cout<<N;	
	
}
