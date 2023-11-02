#include <bits/stdc++.h>

#define MAX 6561
#define MOD 3

using namespace std;

int N;

int star[MAX][MAX] ={0,};
						
void MakeStar(int y, int x, int n, bool empty){
	if(n==1){
		star[y][x] = empty ? ' ' : '*';
		return;
	}

	for(int i = 0 ; i < MOD ; i++){
		for(int j = 0; j < MOD; j++){
			
			if(j == MOD / 2 && i == MOD / 2 ) 
				MakeStar( y + n / MOD * i, x + n / MOD *j, n / MOD, true);
			else 
				MakeStar( y + n / MOD * i, x + n / MOD *j, n / MOD, empty);
		}
	}
}					

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N;
	

	MakeStar(0,0,N,false);
	
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout<< (char)star[i][j];
		}
		cout<<"\n";
	}


	return 0;	
}
