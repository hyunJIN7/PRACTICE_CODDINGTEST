//���ڵ� , ��� 
#include <bits/stdc++.h>
using namespace std;
int h,w;
int maze[101][101],dist[101][101]={0,};
int dx[4] = {0,-1,1,0},dy[4] = {-1,0,0,1};
void dfs(int y, int x, int d ){
	if( x < 0 || x >= w || y < 0 || y >= h||!maze[y][x] ) return;
	//�̹� �Դ� �� �̰� �� �۰ų� ���� ���̶�� ����
	//�� ��� �� �ʿ� ���� 
	if(dist[y][x] && dist[y][x]<=d) return ;
	dist[y][x] = d;
	for(int i = 0 ; i<4 ;i++)
		dfs(y+dy[i],x+dx[i] , d+1);
}
int main(){
	scanf("%d %d",&h,&w);
	for(int i = 0 ; i <h ; i++)
		for(int j = 0 ; j <w ; j++)
			scanf("%1d",&maze[i][j]);
	dfs(0,0,1);
	printf("%d\n",dist[h-1][w-1]);
	return 0;
}

