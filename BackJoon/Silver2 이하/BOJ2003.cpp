#include <iostream>
#include <algorithm> //find
#define MAX 10010
using namespace std;

int N,M;
int accum[MAX]={0,};
int ans=0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>N>>M;
	for(int i = 1,num,sum=0 ; i <= N ;i++){
		cin>>num;
		accum[i] = accum[i-1]+num;
	}
	for(int i = N ; i > 0 ;i--){
		int target = accum[i]-M;
		if(target<0) break;
		if(find(accum,accum+N+1, target) == accum+N+1) continue;
		ans++;
		
	}

	cout<<ans;
}
