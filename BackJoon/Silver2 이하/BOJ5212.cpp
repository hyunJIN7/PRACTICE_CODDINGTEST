#include <iostream>
#include <set>
#include <algorithm> // copy
#include <cstring>

using namespace std;

int H,W;
char plan[10][10];
bool sink[10][10]; 

int minX=10,maxX=0,minY=10,maxY=0;

int dx[4]={0,0,1,-1}, dy[4] = {1,-1,0,0};

bool checkSink(int y, int x){//물에 잠기면 true 
	int cnt = 0 ;
	for(int i = 0 ; i < 4 ;i++){
		int ny = y + dy[i], nx = x+ dx[i];
		if(ny < 0 || ny >= H || nx < 0 || nx>= W){
			cnt++; continue;
		} 
		if(plan[ny][nx]=='.' )
			cnt++;
	}
	sink[y][x] = cnt >= 3;
	
//	cout<<y<<"  "<<x <<" : "<<cnt<<" , "<<sink[y][x]<<endl;
	
	return cnt >= 3;
}
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>H>>W;
	for(int i = 0 ; i < H ; i++){
		for(int j = 0 ; j < W ;j++){
			cin>>plan[i][j];
		}
	}
	
	memset(sink,0,sizeof(sink));// true인 곳만 바꿔서 출력하면 됨.  
	for(int i = 0 ; i < H ; i++){
		for(int j = 0 ; j < W ;j++){
			if(plan[i][j] != 'X') continue;
			if(!checkSink(i,j)){
				minX = min(minX,j);
				maxX = max(maxX,j);
				minY = min(minY,i);
				maxY = max(maxY,i);
//				cout<<"@@ "<<i<<" "<<j<<endl;
//				cout<<"min,max: "<<minX<<","<<minY<< "  "<<maxX<<","<<maxY<<endl;

				
			}
			
				
		}
	}
//	cout<<minY<<","<<minX<< "  "<<maxX<<","<<maxY<<endl;
	for(int i = minY ; i <= maxY ; i++){
		for(int j = minX ; j <= maxX ;j++){
			if(sink[i][j]) cout<<".";
			else cout<<plan[i][j];
		}
		cout<<"\n";
	}
	
}
