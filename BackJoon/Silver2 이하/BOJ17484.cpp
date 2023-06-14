#include <bits/stdc++.h>
#define Fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAX 6

using namespace std;

int N,M; 
int arrSpace[MAX][MAX];
int ans = 0x7f7f7f7f;

void Bruteforce(int y,int x, int dir,int fuel){
	if( x<0 || x>= M ) return;
	if(y == N-1){
		ans = (fuel+arrSpace[y][x] < ans)? fuel+arrSpace[y][x] : ans;
		return;
	}
	
//	cout<<y<<" , "<<x<<" -> fuel : " << fuel+arrSpace[y][x]<<endl;
	
	for(int i = -1 ; i <2 ; i++ ){
		if(dir==i) continue;
		Bruteforce(y+1,x+i,i,fuel+arrSpace[y][x]);
	}
	
} 

int main(){
	Fastio;
	cin>>N>>M;

	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			cin>>arrSpace[i][j];
		}	
	}

	
	
//	Bruteforce(0,0,-2,0);
	for(int j = 0 ; j < M ; j++){ // 시작 위치 바꿔가며 진행  
		Bruteforce(0,j,-2,0);
	}		
	cout<<ans;
}
