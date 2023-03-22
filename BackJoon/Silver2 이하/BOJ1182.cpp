#include <bits/stdc++.h>
#define MAX 20

using namespace std;

int N, S;
int input[MAX];
int result=0;

void Recur(int cur_index,int total){

	if(cur_index==N){
		if(total==S) result++;
		return;
	}
	
	
	Recur(cur_index+1, total);
	Recur(cur_index+1, total+input[cur_index]);	
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>N>>S;
	for(int i = 0 ; i < N ;) cin>>input[i++];
	
	Recur(0,0);	
	if(!S) result--;
	cout<<result ;
}
