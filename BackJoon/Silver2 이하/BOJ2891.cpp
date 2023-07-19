#include <bits/stdc++.h>

using namespace std;
int ans;
int vS[12]={0,},vR[12]={0,};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int N,S,R;//전체 수 , 손상 팀, 여분 팀
	cin>>N>>S>>R;  
	ans = S;
	for(int i = 0,tmp ; i < S ; i++){
		cin>>tmp;
		vS[tmp]=1;
	}
	for(int i = 0,tmp ; i < R ; i++){
		cin>>tmp;
		if(vS[tmp]){
			ans--;//내꺼 여분은 나만 쓴다.
			vS[tmp]=0; 
		}
		else vR[tmp]=1;
	}

	for(int i=1,index;i<= 10;i++){
		if(!vS[i]) continue;
		if(vR[i-1]) index = i-1;
		else if(vR[i+1]) index = i+1;
		else continue;
		
		vR[index]=0;
		ans--;		
	}
	cout<<ans;
	
}

