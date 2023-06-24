#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

priority_queue<pii, vector<pii>, greater<pii>> pq;

int N;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	while(N--){
		int x;
		cin>>x;
		
		if(x){
			pq.push({abs(x),x});
		}
		else{
			if(pq.empty()){
				cout<<"!!!   0\n";
				continue;
			}
//			pii curr = pq.top();
			cout<<"!!!  "<<pq.top().second<<"\n";
			pq.pop();
			
		}
		
	}
	
	
}
