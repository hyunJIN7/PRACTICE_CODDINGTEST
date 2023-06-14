#include <bits/stdc++.h>
#define Fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
int N;
int num=0;
int ans=0;
set<int> s;
void Bruteforce(int depth,int num){
	if(depth > N){
		
		return;
	}
	if(num && !(num%3)  &&   pow(10,N-1)-1 < num){
//		cout<<":$$  " <<num<<"   "<<  <<endl;
//		ans++;
		s.insert(num);
		
	}
	
	Bruteforce(depth+1,num*10);
	Bruteforce(depth+1,num*10+1);
	Bruteforce(depth+1,num*10+2);
	
}

int main(){
	Fastio;
	cin>>N;
	
	Bruteforce(0,0);
//	cout<<ans;
	cout<<s.size();
}
