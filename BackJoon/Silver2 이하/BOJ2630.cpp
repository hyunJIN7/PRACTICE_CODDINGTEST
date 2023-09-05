#include <bits/stdc++.h>

using namespace std;

int N;
int board[128][128]={0,};
int ans[2]={0,};

void DFS(int y,int x, int len){
	if(len==1){
		ans[board[y][x]]++;
		return;
	} 
	int color = board[y][x]; // 비교 기준 색  
	for(int i = y ; i < y+len; i++){
		for(int j = x; j < x + len;j++){
			if(board[i][j] != color){
				DFS(y,x,len/2);
				DFS(y+len/2,x,len/2);
				DFS(y,x+len/2,len/2);
				DFS(y+len/2,x+len/2,len/2);
				return;
			} 
		}
	}
	ans[color]++;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin>>board[i][j];
		}
	}
	
	DFS(0,0,N);
	
	cout<<ans[0]<<"\n"<<ans[1];
}
