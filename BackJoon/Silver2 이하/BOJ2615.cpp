//풀이 참고 https://kibbomi.tistory.com/18 
#include <bits/stdc++.h>
using namespace std;
int checkboard[20][20]={0,}; // 0~18
  
bool row_right(int pivot,int y, int x){
	bool retval = true;
	int cx, cy=y;
	
	//check 5개 
	for(int i = 1; i<5 ; i++){
		cx = x + i;
		if(cx >= 19) return false;
		if(pivot != checkboard[cy][cx]) retval = false;	 
	}
	
	//check 6
	if(retval){
		//오른쪽으로 6개 이상 
		cx = x + 5;
		if(cx < 19)
			if(pivot == checkboard[cy][cx]) return false;
		
		//왼쪽으로 6개 이상 
		cx = x-1;
		if(cx>=0)
			if(pivot == checkboard[cy][cx]) return false; 
	}
	return retval;
}

bool colum_down(int pivot,int y, int x){
	bool retval = true;
	int cx=x, cy;
	
	//check 5개 
	for(int i = 1; i<5 ; i++){
		cy = y + i;
		if(cx >= 19) return false;
		if(pivot != checkboard[cy][cx]) retval = false;	 
	}
	
	//check 6
	if(retval){
		cy = y + 5;
		if(cy < 19)
			if(pivot == checkboard[cy][cx]) return false;
		
		cy = y-1;
		if(cy>=0)
			if(pivot == checkboard[cy][cx]) return false; 
	}
	return retval;
}
bool diag_rightdown(int pivot,int y, int x){
	bool retval = true;
	int cx, cy;

	//check 5개 
	for(int i = 1; i<5 ; i++){
		cx = x + i;
		cy = y + i;
		if(cx >= 19 || cy >= 19) return false;
		if(pivot != checkboard[cy][cx]) retval = false;	 
	}
	
	//check 6
	if(retval){
		cx = x + 5;
		cy = y + 5;
		if( cx < 19 && cy < 19 )
			if(pivot == checkboard[cy][cx]) return false;
		
		cx = x- 1;
		cy = y - 1;
		if(cx >= 0 && cy>=0)
			if(pivot == checkboard[cy][cx]) return false; 
	}
	return retval;
}
bool diag_rightup(int pivot,int y, int x){// 워치, 바둑 색  
	bool retval = true;
	int cx, cy;

	//check 5개 
	for(int i = 1; i<5 ; i++){
		cx = x + i;
		cy = y + i*(-1);
		if(cx >= 19 || cy < 0 ) return false;
		if(pivot != checkboard[cy][cx]) retval = false;	 
	}
	
	//check 6
	if(retval){
		cx = x + 5;
		cy = y - 5;
		if( cx < 19 && cy >= 0 )
			if(pivot == checkboard[cy][cx]) return false;
	
		cx = x - 1;
		cy = y + 1;
		if(cx >= 0 && cy < 19 )
			if(pivot == checkboard[cy][cx]) return false; 
	}
	return retval;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

	for(int i = 0 ; i < 19;i++){
		string tmp;
		getline(cin, tmp);
		for(int j = 0 ; j < 19 ; j++){
			checkboard[i][j] = tmp[j*2]-'0';
		}
	}
	
	for(int i = 0 ; i < 19;i++){
		for(int j = 0 ; j < 19 ; j++){
			if(checkboard[i][j]){
				if(row_right(checkboard[i][j],i,j) ||
					colum_down(checkboard[i][j],i,j) ||
					diag_rightdown(checkboard[i][j],i,j) ||
					diag_rightup(checkboard[i][j],i,j)
				) {
					cout<<checkboard[i][j] <<"\n"<<i+1 << " " <<j+1;
					return 0;	
				}
			}
		}
	}
	cout<<"0";	
	
}
