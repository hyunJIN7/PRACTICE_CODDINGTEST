#include <bits/stdc++.h>

using namespace std;

int DY[4]={1,0,-1,0};
int DX[4]={0,1,0,-1};

int xMin,xMax,yMin,yMax;
set<pair<int,int>> S;
map<char,int> M;
int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int N;
	string way;
	cin>>N>>way;
	
	M.insert({'F',1});
	M.insert({'B',-1});
	M.insert({'R',1});
	M.insert({'L',3});
	
	
	
	int dIndex=2; // 현재 방향  
	int cy=0,cx=0;//현재 위치  
	
	yMin=cy;
	yMax=cy;
	xMin=cx;
	xMax=cx;
	S.insert({cy,cx});
	
	for(int i = 0 ; i < N ; i++){
		int dy = DY[dIndex], dx = DX[dIndex];		
		if(way[i]=='F'||way[i]=='B'){
			cy = cy + M[way[i]]*dy;
			cx = cx + M[way[i]]*dx;
		}
		else if (way[i]=='R'||way[i]=='L'){
			dIndex  = (dIndex+M[way[i]])%4;
			dy = DY[dIndex];
			dx = DX[dIndex];
		}
		S.insert({cy,cx});
		yMin=min(cy,yMin);
		yMax=max(cy,yMax);
		xMin=min(cx,xMin);
		xMax=max(cx,xMax);		

	}
	
	for(int i = yMax-yMin ; i >=0; i--){ // y는 반대로 출력해줘야 내 풀이에 맞음. 
		
		for(int j = 0 ; j <= xMax-xMin; j++){
			int y = i + yMin;
			int x = j + xMin;
		
			(S.find({y,x}) != S.end() ) ? cout<<"." : cout<<"#";
			
		}
		
		cout<<"\n";
	}	
}
