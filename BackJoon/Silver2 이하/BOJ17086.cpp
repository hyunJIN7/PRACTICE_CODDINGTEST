/*
상어가 없는 빈칸에서 시작해서 상어가 있는 곳까지 최대 거리 구하는 문제.
상어 있는 곳에서 시작하면 고려해야할 사항이 더 생김 
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring> //for memset

using namespace std;
#define MAX 50

int W,H, ans = 0;
int MAP[MAX][MAX];
bool Visit[MAX][MAX]={0,};
vector<pair<int,int>> yx; // 상어 없는 칸  

int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};

void Input(){
	cin>>H>>W;
	for(int i = 0 ; i < H; i++){
		for(int j = 0 ; j < W; j++){
			cin>>MAP[i][j];
			if(MAP[i][j] ==0) yx.push_back({i,j}); 
		}
	}
}

struct Node{
	int y,x,distance;
	Node(int a, int b,int dis){
		y = a;
		x = b;
		distance = dis;
		
	}
};

int BFS(int y,int x){
	queue<Node> que;
	Node start = {y,x,0};
	que.push(start);
	Visit[y][x] = true;
	
	while(!que.empty()){
		Node target = que.front();
		que.pop();
		
		if(MAP[target.y][target.x]==1)	return target.distance;
		
		for(int i= 0 ; i < 8 ; i++){
			int cy = target.y + dy[i];
			int cx = target.x + dx[i];
			if(cy<0 || cy>=MAX || cx<0 ||cx>=MAX) continue;
			if(!Visit[cy][cx]){
				Visit[cy][cx]=true;
				que.push({cy,cx,target.distance+1});
			}
		}
	}
} 

void Solution(){
	for(auto e : yx){
		int y = e.first;
		int x = e.second;	
		memset(Visit,false,sizeof(Visit));	
		
		int tmp = BFS(y,x);
		if(tmp > ans) ans = tmp;
	
	}
}

void Solve(){
	Input();
	Solution();
	cout<<ans;	
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Solve();
	
}
