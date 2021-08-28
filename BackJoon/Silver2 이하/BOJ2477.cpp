//참고 https://mygumi.tistory.com/278
// 수학적 사고 필요  
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int k;
	int edge[7];
	int max_w=0,max_h=0; //어째든 홀짝 중 하나는 h,w 
	cin >> k;
	for(int i = 0,tmp ; i < 6 ; i++){
		cin>>tmp >>edge[i];
		if(i%2){
			max_h = max(max_h,edge[i]); 
		}
		else{
			max_w = max(max_w,edge[i]); 
		}
	}
	int w,h;
	for(int i = 0 ; i < 6 ; i++){
		int tmp = edge[(i+5)%6] + edge[(i+1)%6];
		if(i%2){
			if(tmp == max_w) w = edge[i];
			
		}
		else{
			if(tmp == max_h) h = edge[i];	
			 
		}
	}
	cout << (max_w*max_h - w*h) * k;
	
}
