#include <iostream>
#include <vector>
#include <algorithm> // find

using namespace std;
#define MAX 5

int dx[4] = {0,0,1,-1},dy[4] = {1,-1,0,0};
int board[MAX][MAX];
vector<int> vecAns;

void Input(){
	//인풋 더 간단하게 하는 법 없나? 
	for(int i = 0; i < MAX ; i++)
		for(int j = 0 ; j < MAX ;j++)
			cin>>board[i][j];
}

void DFS(int y, int x, int num ,int depth){
	if( y<0 or y>= MAX or x<0 or x>=MAX ) return;
	
	int currentNum = num*10+board[y][x];
	
	
	if(depth == MAX){
		if(find(vecAns.begin(), vecAns.end(), currentNum) == vecAns.end()) //vector에 없다면 넣기  
			vecAns.push_back(currentNum);
			
		return;
	}
	
	for(int i = 0 ; i < 4; i++){
		DFS(y+dy[i],x+dx[i],currentNum,depth+1);
	}
}
 
void Solution(){
	for(int i = 0; i < MAX ; i++)
		for(int j = 0 ; j < MAX ;j++)
			DFS(i,j,board[i][j],0);
	cout<<vecAns.size();
}

void Solve(){
	Input();	
	Solution();
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	Solve();
}
