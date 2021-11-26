#include <bits/stdc++.h>
using namespace std;
char rgb1[101][101],rgb2[101][101];
int n,ans1=0,ans2=0;
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
void dfs1(int y, int x, char c){
	if( y<0||y>=n||x<0 ||x>=n ||rgb1[y][x] == 0 ) return;
	if(rgb1[y][x] != c) return;
	rgb1[y][x] = 0;
	for(int i = 0 ; i< 4 ; i++)	dfs1(y+dy[i],x+dx[i],c);
}  
void dfs2(int y, int x,char c){ // c : ÇöÀç Ã£À» ±×·ì 
	if( y<0||y>=n||x<0 ||x>=n || rgb2[y][x] == 0 ) return;
	if(rgb2[y][x] == 'B'){
		if( c != 'B') return;
	}
	else{ // R,G ÀÎ°æ¿ì 
		if( c == 'B') return;
	}
	rgb2[y][x] = 0;
	for(int i = 0 ; i< 4 ; i++)	dfs2(y+dy[i],x+dx[i],c);
}
int main(){
	cin>>n;  
	for(int i = 0,j=0 ; i < n;i++,j=0){
		string s;
		cin>>s;
		for(auto e : s) {
			rgb1[i][j] = e;
			rgb2[i][j++] = e;	
		}
	}
	for(int i = 0; i < n ; i++){
		for(int j = 0 ; j < n ;j++){
			if(rgb1[i][j]!=0){
				dfs1(i,j,rgb1[i][j] );
				ans1++;
			}
			if(rgb2[i][j]!=0){
				dfs2(i,j, rgb2[i][j]);
				ans2++;
			}
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
