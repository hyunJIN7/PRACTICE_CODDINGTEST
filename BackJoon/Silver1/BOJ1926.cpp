#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int H,W;
int paper[MAX][MAX]; 

int numGroup=0,maxArea=0;
int area=0; 
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

void DFS(int y, int x){
	if(y < 0 || y>=H || x<0 ||x>=W) return;
	if(!paper[y][x]) return;
	area++;
	paper[y][x] = 0;
	
	for(int i = 0 ; i < 4 ; i++){
		DFS(y + dy[i],x + dx[i]);
	}
	
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>H>>W;
	for(int i = 0 ; i < H ; i++){
		for(int j = 0 ; j < W ; j++){
			cin>>paper[i][j];
		}
	}
	

	for(int i = 0 ; i < H ; i++){
		for(int j = 0 ; j < W ; j++){
			if(paper[i][j]){
				area=0;
				DFS(i,j);
				numGroup++;
				maxArea = ( maxArea < area )? area : maxArea;
			}
		}
	}

	cout<<numGroup <<"\n"<<maxArea;	
}
