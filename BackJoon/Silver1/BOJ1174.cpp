//https://his130.tistory.com/206
//https://henry121407.tistory.com/229
//https://lyzqm.blogspot.com/2017/12/1038-1174.html
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void MakeIncreNum(ll num, int level, vector<ll>& v){
	if(level > 10) return;
	v.push_back(num);
	for(int i = num%10-1 ; i>=0 ;i--){
		MakeIncreNum(num*10 + i, level+1, v);
	}
}

//최대 수는 9876543210 -> 10자리 , 이 이상 나올 수 없다. 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<ll> v;
	for(int i = 0; i <= 9 ; i++){
		MakeIncreNum(i,1,v);
	}
	
	sort(v.begin(),v.end());
	
	(n > v.size()) ? cout<< "-1" : cout<< v[n-1]  ;
	
}
