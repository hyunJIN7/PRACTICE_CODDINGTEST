#include <bits/stdc++.h>

#define MAX 1000000
#define NUM_BTN 10


using namespace std;

int N, M;

bool can_use[NUM_BTN], can_make[MAX] = {0,};
vector<int> btn; // 누를 수 있는 숫자 버튼  

int ans = INT_MAX;

void BackTrack(int num, int depth){
	if(num >= MAX) return;
	
	int cnt = depth + abs(N - num);
	ans = min(ans, cnt);
//	if(num == 14124) cout<< cnt<<"!!! \n";

	if(can_make[num]) return;
	can_make[num] = true;
	
	for(int i = 0 ; i < btn.size(); i++){
		int next_num = num*10 + btn[i];
		int next_cnt = depth + abs(N - next_num);
		if( cnt < next_cnt) continue;
		BackTrack( next_num , depth + 1);
	}
		
	
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	memset(can_use, true, sizeof(can_use));
	
	cin >> N >> M;
	for(int i = 0 ; i < M ; i++){
		int num; cin >> num;
		can_use[num] = false;
	}
	for(int i = 1 ; i < NUM_BTN; i++)
		if(can_use[i]) btn.push_back(i);	
	if(can_use[0]) btn.push_back(0); // 0 마지막에 넣어야해  
		
	
	ans = abs(N - 100);
	for(int i = 0 ; i < btn.size(); i++) 
		BackTrack(btn[i], 1);


	cout<<ans;
	
	return 0;	
}
