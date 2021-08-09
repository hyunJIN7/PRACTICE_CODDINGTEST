#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
queue<pair<int,int>> q;
int A,B,C;
bool visited[201][201]={0,};
void pour(int x,int y){
	if(!visited[x][y]){
		visited[x][y]=true; //A,B의 용량이 다르니까 y,x=true는 안해도 될듯
		q.push({x,y});
	}
}

BFS(){
	q.push({0,0});
	visited[0][0]=true;
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		int z = C - x - y;
		if(!x) ans.push_back(z);
		q.pop();
		
		//A->B
//		y = (x+y <= B) ? x+y : B;
//		x = (x+y <= B) ? 0 : x+y-B;
//		visited[x][y]=true; 
//		q.push({x,y});
		int water = min(x,B-y); //이동할 물의 양 
		pour(x-water,y+water); 

		// A->C
		water = min(x,C-z); 
		pour(x-water,y); 
		
		//B->A
		water = min(A-x,y); 
		pour(x+water,y-water); 

		//B->C
		water = min(y,C-z);
		pour(x,y-water);

		//C->A
		water = min(A-x,z);
		pour(x+water,y);
		
		//C->B
		water = min(B-y,z);
		pour(x,y+water);
	}
	
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>A>>B>>C;
	BFS();
	sort(ans.begin(),ans.end());
	for(auto e : ans) cout<<e<<" ";
	
}
