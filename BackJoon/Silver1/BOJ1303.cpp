#include <bits/stdc++.h>
#define MAX 101

using namespace std;

int H,W;
char battlefield[MAX][MAX];
bool check[MAX][MAX]={0,};

int ans[2]={0,0};
int cnt =0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void DFS(int y, int x, char c){
	if(y < 0 || y>= H || x<0 || x>W || check[y][x]) return;
	
	if(battlefield[y][x]!=c) return;
	cnt++;
	check[y][x]=true;
	for(int i = 0 ; i < 4 ;i++){
		DFS(y+dy[i],x+dx[i],c);
	}
	
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>W>>H;
	
	for(int i = 0 ; i < H ; i++){
		for(int j = 0 ; j < W ; j++){
			cin>>battlefield[i][j];
		}
	}
	
	
	
	
	for(int i = 0 ; i < H ; i++){
		
		for(int j = 0 ; j < W ; j++){
			if(check[i][j]) continue;

			DFS(i,j,battlefield[i][j]);
			
			int index = (battlefield[i][j]=='W')?0:1;
			ans[index] += (cnt*cnt);
			cnt = 0;
		}
		
	}
	cout<<ans[0]<<" "<<ans[1];
	
	
}
