#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct node{	int s,e;};
int n;
node times[200000];

bool compare(node a, node b){
	return (a.s==b.s)?  a.e<b.e : a.s<b.s ;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i = 0 ; i < n; i++){
		cin>>times[i].s>>times[i].e;
	}
	
	sort(times,times+n,compare);
	
	priority_queue<int , vector<int>, greater<int>> q;//오름차순
	q.push(times[0].e);
	for(int i = 1 ; i < n ; i++){
		//end 시간이 먼저 인것부터 top됨
		 int s = times[i].s, e = times[i].e;
		 int now = q.top();
		 
		 if(now>s){//겹치는경우 
		 	q.push(e);
		 }
		 else{
		 	q.pop();
			q.push(e);	
		 }	
	}
	cout<<q.size();
	 
	
}

