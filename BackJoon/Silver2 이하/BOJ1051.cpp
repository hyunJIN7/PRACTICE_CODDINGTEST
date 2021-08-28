#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int h,w;
	int square[51][51];
	cin >> h >> w;
	
	for(int i=0;i<h;i++){
		string tmp;
		cin>>tmp;
		for(int j = 0 ; j < w;j++){
			square[i][j] = tmp[j]-'0';
		}
	}
	int size = min(h,w);
	
	while(size){
		// 전체 사각형  
		for(int i = 0 ; i+size <= h ; i++){
			for(int j = 0 ; j+size <= w; j++){
				int ref = square[i][j];
				if(ref == square[i][j+size-1] && ref == square[i+size-1][j+size-1] && ref == square[i+size-1][j] ){
					cout<<size*size;
					return 0;
				}	
			}
		}
		size--;
	}
	
}
