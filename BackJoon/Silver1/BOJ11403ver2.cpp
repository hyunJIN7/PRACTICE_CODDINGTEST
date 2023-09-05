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
			
	
	/*
	- 가로 세로 접근 순서 주의
	- i->j->k를 확인하는데 j를 올수 있는 i들을 먼저 확인 
						=> 즉 , 세로로 탐색 , 가로 먼저 가면 틀림  
	*/
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
