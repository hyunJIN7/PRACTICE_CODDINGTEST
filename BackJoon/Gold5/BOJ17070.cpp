#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

int N;
int map[16][16];
int ans= 0 ; 

int dy[3] = {0,1,1}; // 가로0, 대각선1, 세로2
int dx[3] = {1,1,0};

void DFS(int y, int x ,int dir){
   if(y==N-1 && x ==N-1){
		ans++;
		return;
   }
   
   for(int i = 0 ; i < 3 ; i++){
//   		if( (dir==0 && i ==2)  || (dir==2 && i==0) ) continue;
		if(abs(dir-i)==2) continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny >= N || nx >= N || map[ny][nx]) continue;
		
		
		if( i==1 && (map[y+1][x] || map[y][x+1]) ) continue;
			
		DFS(ny,nx,i);
		
		
   }
   

}

int main(){
   ios::sync_with_stdio(false); cin.tie(NULL);
   cin>>N;
   for(int i = 0 ; i < N ; i++){
   	
		for(int j = 0 ; j < N ; j++){
		 cin>>map[i][j];
		}
   }
   
   if(!map[N-1][N-1]) DFS(0,1,0);   
   cout<<ans;
   
   return 0;
}
