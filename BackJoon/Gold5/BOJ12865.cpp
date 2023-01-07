//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N,K;
int val[100010][101]={0,}; // 각 행 담을 수 있는 무게 , 열 각 물건 -- > 가치 배열  
vector <pair<int,int>> item;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>K;
	
	item.push_back({0,0});
	for(int i = 0 ; i < N; i++){
		int w,v;
		cin>>w>>v;
		item.push_back({w,v});
	}

	
	for(int i = 1 ; i <= K; i++){
		 
		for(int j = 1 ; j <= N ;j++){
			if( item[j].first <= i  ){
				val[i][j] = max(val[i][j-1],	val[  i - item[j].first   ][j-1] + item[j].second );	
				
			}
			else{ // wk < W
				val[i][j] = val[i][j-1];
			}
			
		}
		
	}
	
	
	
	
	
	cout<<val[K][N];
}
