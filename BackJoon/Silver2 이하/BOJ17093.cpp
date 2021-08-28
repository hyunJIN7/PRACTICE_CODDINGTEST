#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	vector<pair<ll,ll>> p,q;
	while(n--){
		ll x,y;
		cin >> x >> y;
		p.push_back({x,y}); 
	}
	while(m--){
		ll x,y;
		cin >> x >> y;
		q.push_back({x,y}); 
	}
	long long ans=0;
	for(auto i : p){
		for(auto j : q ){
			long long tmp = (i.first-j.first)*(i.first-j.first) 
							+(i.second-j.second)*(i.second-j.second);
			ans = max(ans , tmp );
		}
	}
	cout << ans;
}
