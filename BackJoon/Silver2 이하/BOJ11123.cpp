#include <bits/stdc++.h>
#define MAX 101

using namespace std;

char arr[MAX][MAX]={0,};
bool visited[MAX][MAX]={0,};
int T,H,W;

int dx[4]={0,0,1,-1};
int dy[4] ={1,-1,0,0};
void DFS(int y, int x){
	if(y < 0 || y>= H || x<0 || x>= W ) return;
	if(visited[y][x] || arr[y][x]=='.') return;
	
	
	visited[y][x] = true;
	
	for(int i=0 ; i < 4 ; i++){
		DFS(y+dy[i],x+dx[i]);
		
	}
	
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		int ans = 0;
		cin>>H>>W;
		
		for(int i = 0 ; i < H ; i++){
			for(int j = 0 ; j < W; j++){
				cin>>arr[i][j];
			}
		}
	
		memset(visited , 0 , sizeof(visited) );
		
		for(int i = 0 ; i < H ; i++){
			for(int j = 0 ; j < W; j++){
				if(arr[i][j]=='#' && !visited[i][j] ){
					DFS(i,j);
					ans++;
				}
			}
		}
	cout<<ans<<"\n";
	}
		
}

