#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int N;
vector<int> inputNum,inputOP;
int ansMAX, ansMin;

//string OP[]={"+","-","*","/"};
int arr[11]; // 적용할 연산  
bool visited[50]={0,};  // inputOP의 방문 여부  
int M; //inputOP의 크기  
set<int> ans;

int Calc(int a, int b, int op){
	if(!op) return a+b;
	if(op==1) return a-b;
	if(op==2) return a*b;
	if(op==3) return a/b;
}

void Backtrack(int index_arr){
	if(index_arr == N-1){
		int num = inputNum[0];
		for(int i = 0 ; i <N-1;i++){
			num = Calc(num, inputNum[i+1],arr[i]);
		}
		ans.insert(num);
		return;
	}
	
	for(int i = 0 ; i < M ; i++){
		if(!visited[i]){
			arr[index_arr] = inputOP[i];
			visited[i] = true;
			Backtrack(index_arr+1);
			visited[i] = false;
		}
		
	}
	
}

int main(){
	ios::sync_with_stdio(0);	
	cin>>N;
	for(int i = 0,num ; i < N ; i++) {
		cin>>num;
		inputNum.push_back(num);
	}
	for(int i = 0 ; i < 4 ; i++){
		int num; cin>>num;
		for(int j = 0 ; j < num ;j++ ){
			inputOP.push_back(i);
		}
	}
	M = inputOP.size();
	
	Backtrack(0);	
	cout<<*ans.rbegin()<<"\n" <<*ans.begin();
	
}
