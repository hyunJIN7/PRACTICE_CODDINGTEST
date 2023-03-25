#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;
typedef long long ll;
const long long MAX = 1000000000LL;

int S,T;
string OP[] = { "*", "+", "-", "/" };
set<ll> visited;
 
int Calc(ll a, int op){
	if(!op) return a*a;
	else if(op==1) return a + a ;
	else if(op==2) return a - a  ;
	else if(op==3) return a / a  ;
} 
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>S>>T;
	
	if(S==T){
		cout<<"0\n";
		return 0;	
	} 
	queue<pair<int,string>> q;
	q.push({S,""});
	visited.insert(S);
	while(!q.empty()){
		int currX = q.front().first;
		string currOp = q.front().second;
		q.pop();

		if(currX == T){
			cout<<currOp;
			return 0;
		}
	
		if(currX < 1 || currX > MAX) continue;
		
		for(int i = 0 ; i < 4 ;i++){
			ll newX = Calc(currX,i);
			if(visited.find(newX) != visited.end()) continue; //방문 안한곳만 
			visited.insert(newX);
			q.push({newX, currOp + OP[i] });
		}
	
	}
	cout<<"-1\n";
	
}
