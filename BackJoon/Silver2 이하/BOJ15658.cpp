#include <bits/stdc++.h>

#define MAX 12
#define OP_NUM 4
#define ADD 0
#define MINUS 1
#define MULTIPLY 2
#define DIVIDE

using namespace std;

int N;
int num[MAX];
int operate[OP_NUM];

int arr[OP_NUM] = {0,};

int ans_min = INT_MAX, ans_max = INT_MIN;

void Input(){
	cin >> N;
	for(int i = 0 ; i < N ; i++) cin >> num[i];
	for(int i = 0 ; i < OP_NUM; i++) cin >> operate[i];
}

int Calc(int num1, int num2, int op){
	if(op == ADD) return num1 + num2;
	if(op == MINUS) return num1 - num2;
	if(op == MULTIPLY) return num1 * num2;
	return num1 / num2; //num2 == 0 인 경우는 주어지지 않음  
}

void Backtrack(int accum, int depth){
	if(depth == N){
		ans_max = max(ans_max , accum);
		ans_min = min(ans_min , accum);
		return;
	}
	
	for(int op = 0 ; op < OP_NUM ; op++){
		if(arr[op] < operate[op]){
			arr[op]++;
			Backtrack(Calc(accum,num[depth],op) , depth + 1);
			arr[op]--;
		}		
	}	
}

void Solve(){
	Input();	
	
	for(int op = 0 ; op < OP_NUM ; op++){
		if(operate[op]){
			arr[op]++;
			Backtrack(Calc(num[0],num[1],op) , 2);
			arr[op]--;
		}		
	}

	cout<< ans_max << "\n" << ans_min;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	Solve();
	return 0;	
}
