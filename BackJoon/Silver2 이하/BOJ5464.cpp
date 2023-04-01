#include <bits/stdc++.h>

using namespace std;

int N,M;//��������,���� �� 
int Rs[101],Wk[10001];//�������� ����,���� ����, 1���� ����  

queue<int> q;//��� ���� (�̹� �� ���� ������ ��� ����ϴ� ����) 
priority_queue<int,vector<int>,greater<int>> park;//�� ���� �ڸ�,��������  
int ans = 0 ; 

void Enter(int num){
	if(park.empty()){//�� �����ڸ� ���� ��� 
		q.push(num);
		return;
	}
	
	// �����ڸ� �ִ� ���  
	ans = ans + Rs[park.top()] *  Wk[num];
	Wk[num]= park.top(); //���� ���� ��� ���� ��ġ ǥ��  
	
	cout<<"######## " << num <<endl;
	cout<<num<<" : "<<park.top()<<"�� ����, "<<ans<<endl;
	
	park.pop();
	
} 
void Departure(int num){ // ����  
	park.push(Wk[-1*num]); //���� ������ ��ġ ��������� ���ֱ� 
	cout<<"-------- " << num <<endl;
	cout<<"���� �ڸ� ���� : "<< Wk[-1*num]<<endl ;
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
