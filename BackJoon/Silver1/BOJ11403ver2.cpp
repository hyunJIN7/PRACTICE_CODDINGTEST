#include <bits/stdc++.h>

using namespace std;

int v[100][100]={0,};
int N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);


	cin>>N;
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < N ; j++) cin>>v[i][j];
			
	
//	for(int i = 0; i < N ; i++){
//		for(int j = 0 ; j < N ; j++){
//			for(int k = 0 ; k < N ; k++){
//				if(v[i][j] && v[j][k]) v[i][k]=1; 
//			}
//		}
//	}
	for(int j = 0 ; j < N ; j++){
		for(int i = 0; i < N ; i++){
			for(int k = 0 ; k < N ; k++){
				if(v[i][j] && v[j][k]) v[i][k]=1; 
			}
		}
	}


	for(int i = 0; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
	}


}
