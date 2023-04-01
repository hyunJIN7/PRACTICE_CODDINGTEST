#include <bits/stdc++.h>

using namespace std;

int N,M;//주차공간,차량 수 
int Rs[101],Wk[10001];//주차공간 무게,차량 무게, 1부터 시작  

queue<int> q;//대기 순서 (이미 다 차서 못들어온 경우 대기하는 차량) 
priority_queue<int,vector<int>,greater<int>> park;//빈 주차 자리,내림차순  
int ans = 0 ; 

void Enter(int num){
	if(park.empty()){//빈 주차자리 없는 경우 
		q.push(num);
		return;
	}
	
	// 주차자리 있는 경우  
	ans = ans + Rs[park.top()] *  Wk[num];
	Wk[num]= park.top(); //차량 무게 대신 주차 위치 표시  
	
	cout<<"######## " << num <<endl;
	cout<<num<<" : "<<park.top()<<"에 주차, "<<ans<<endl;
	
	park.pop();
	
} 
void Departure(int num){ // 출차  
	park.push(Wk[-1*num]); //기존 주차한 위치 빈공간으로 해주기 
	cout<<"-------- " << num <<endl;
	cout<<"주차 자리 생김 : "<< Wk[-1*num]<<endl ;
	if(!q.empty()){
		Enter(q.front()); 
		q.pop();	
		
	} 
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i = 1 ; i <= N; i++){
		cin>>Rs[i];
		park.push(i);
	} 
	for(int i = 1 ; i <= M; i++) cin>>Wk[i];	
	
	for(int i = 0 ; i < 2*M ;i++){
		int num ; cin>>num;
		if(num>0) Enter(num);
		else Departure(num);
	}
	
	cout<<ans;
	
} 
