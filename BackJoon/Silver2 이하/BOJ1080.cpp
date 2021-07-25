#include <bits/stdc++.h>
#define MAX 50
using namespace std;
int n,k,ans=0;
int A[MAX][MAX],B[MAX][MAX];

void InvertMatrix(int y,int x ){
	for(int dy = 0 ; dy < 3;dy++){
		for(int dx = 0 ; dx<3;dx++){
			A[y+dy][x+dx] = 1-A[y+dy][x+dx];
		}

	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	bool isSame;
	cin>>n>>k;

	for(int i = 0 ; i<n ; i++){
		string line;
		cin >>line;
		for(int j = 0 ;j<k;j++){
			A[i][j] = line[j] -'0';
		}
	}
	for(int i = 0 ; i<n ; i++){
		string line;
		cin >>line;
		for(int j = 0 ;j<k;j++){
			B[i][j] = line[j] -'0';
		}
	}
	

	//3x3 이상 
	if(n>=3 &&k>=3){
		for(int i =0 ;i < n-2;i++){
			for(int j = 0 ; j < k-2 ;j++){
				if(A[i][j] != B[i][j]) {
					InvertMatrix(i,j);
					ans++;
				}
			}
		}
	
	}  
	//같은지 확인   
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ;j<k;j++){
			if(B[i][j] != A[i][j] ){
				cout<<"-1";
 				return 0;
			}
		}
	}
	cout<<ans;

	
}
