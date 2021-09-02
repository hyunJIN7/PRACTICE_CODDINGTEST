#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	priority_queue<int,vector<int>,greater<int>> pq;//오름차순 
	
	for(int i = 0,tmp ; i < n*n ; i++){
		cin>>tmp;
		if(pq.size()>n){
			pq.pop();
		}
		pq.push(tmp);
	}
	pq.pop();
	cout<<pq.top();
}
