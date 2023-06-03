#include <bits/stdc++.h>

using namespace std;

int C,S,T;//테스트 케이스 ,태균 ,상대 

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C;
	while(C--){
		cin>>S>>T;

		queue<tuple<int,int,int>> q;
		
		q.push(make_tuple(S,T,0));
		int cS,cT,cnt;
		while(!q.empty()){
			tie(cS,cT,cnt) = q.front();
			q.pop();

			
			if(cS > cT) continue;
			if(cS == cT) break;

			q.push(make_tuple(cS*2, cT+3, cnt+1  ));
			q.push(make_tuple( cS+1, cT, cnt+1 ));	
		}
		
		cout<<cnt<<"\n";
	}
	

	
	
	
}
