#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N;
	priority_queue<double> pq;
	
	cin>>N;
	for(int i = 0 ; i < N ; i++){
		double num; cin>>num;
		pq.push(num);	
	}
	double ans = pq.top();
	pq.pop();
	
	while(!pq.empty()){
		ans += pq.top()/2;
		pq.pop();
	}
	
	cout<<ans;
	
	

}
