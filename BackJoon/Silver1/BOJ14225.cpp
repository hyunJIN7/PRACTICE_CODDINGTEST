#include <iostream>
#include <map>


// 시간 복잡도, 비트 마스킹  
using namespace std;
int N;
int input[20];
map<int,int> m;
void Backtrack(int curr_index, int total){
	if(curr_index==N){
		m[total]++;
		return;
	}
	
	Backtrack(curr_index+1, total+input[curr_index]);
	Backtrack(curr_index+1, total);
	
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i = 0 ; i < N;) cin>>input[i++];
	Backtrack(0,0);
	
	for(int i =1 ; ; i++ ){
		if(m[i]) continue;
		cout<<i;
		break;
		
	}
	
}
