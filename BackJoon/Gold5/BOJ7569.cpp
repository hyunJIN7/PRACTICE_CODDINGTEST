#include <bits/stdc++.h>
using namespace std;
int box[101][101][101]={0,};
int h,n,m;
int ans=0;
struct pos{
	int x,y,z;
};
queue<pos> q;
int dz[6]={-1,1,0,0,0,0},dy[6]={0,0,0,0,1,-1},dx[6]={0,0,1,-1,0,0};

void Input(){
	cin >>m >> n >> h;
	for(int i = 0 ; i < h;i++){
		for(int j = 0 ; j < n;j++){
			for(int k = 0 ; k < m;k++){
				cin >> box[i][j][k];
				if(box[i][j][k]==0) numOfNotRipe++;
				else if(box[i][j][k]==1){
					q.push({i,j,k});	
				}
			}
		}
	}
}


void Solution(){

 while (!q.empty()) {
        int x = q.front().x, y = q.front().y, z = q.front().z;
        q.pop();
        for (int i=0; i<6; i++) {
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
            if (box[nx][ny][nz]) continue;    // Ripened(1 or above), empty(-1)
            box[nx][ny][nz] = box[x][y][z] + 1; // Day count
            q.push({nx, ny, nz});
        }
    }


	
	for(int i = 0 ; i < h;i++){
		for(int j = 0 ; j < n;j++){
			for(int k = 0 ; k < m;k++){
			
				if(box[i][j][k]==0) {
					cout<<"-1";
					return;
				}
				if (ans < box[i][j][k]) ans = box[i][j][k];

			}
		}
	}
	cout<< ans-1;
 	//numOfNotRipe ==0 ? cout<< ans : cout<< "-1";

}

void Slove(){
	Input();
	Solution();
} 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	Slove();
		
	
}
