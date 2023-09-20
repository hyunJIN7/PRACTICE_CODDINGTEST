#include <iostream>
#include <vector>
#include <cstring>

#define endl "\n"
#define MAX 51
#define PLAYER_NUM 9 

using namespace std;
 
int N,ans=0;//이닝 수  
int game[MAX][PLAYER_NUM]={0,}; // 각 이닝에서 선수 능력치
int order[PLAYER_NUM]; // 타순 저장 배열
bool visited[PLAYER_NUM]={0,}; // 각 선수 선택했는지      

void Input(){
	cin>>N;
	for(int i = 0 ; i < N; i++)
		for(int j = 0; j < PLAYER_NUM; j++ )
	 		cin>>game[i][j];
}

void Play_Game(){
	
	int score = 0; 
	int start_player = 0;
	int base_state[3];   
	
	for(int i = 0; i < N ; i++){ // 이닝 
		memset(base_state,0,sizeof(base_state));
		int out_cnt = 0;
		while(out_cnt <= 2 ){ 
			int Player = game[i][order[start_player]];
			if(!Player) out_cnt++; //0이면 
			else if(Player==1){ // 안타 
				for(int b = 2 ; b >= 0 ; b--){
					if(base_state[b]){//점수 있는 base 
						if(b==2){
							score++;								
						}
						else{
							base_state[b+1]=1;
						}
						base_state[b]=0;
					}
					
				}
				base_state[0]=1;	 
			}
			else if(Player==2){ // 2루타  
				for(int b = 2 ; b >= 0 ; b--){
					if(base_state[b]){
						if(b > 0) score++;
						else base_state[b+2]=1;
						base_state[b]=0;
					}
				}
				base_state[1]=1;		
			}
			else if(Player==3){ // 3루타  
				for(int b = 2 ; b >= 0 ; b--){
					if(base_state[b]){
						score++;
						base_state[b]=0;								
					}
				}
				base_state[2]=1;
			}
			else{ // 홈런  
				for(int b = 2 ; b >= 0 ; b--){
					if(base_state[b]){
						score++;
						base_state[b]=0;								
					}
				}
				score++;
			}
			
			start_player = (start_player+1)%PLAYER_NUM;

		} 
		
	}
	ans = (ans < score)? score : ans;
	
}

void DFS(int index){ // order의 index  
	if(index == PLAYER_NUM){
		Play_Game();
		return;
	}
	
	for(int i = 1 ; i < PLAYER_NUM ; i++){
		if(visited[i]) continue;
		visited[i]=true;
		order[index]=i;
		if(index==2) DFS(index+2);//3번째는 정해졌으니 	
		else DFS(index+1);	
		visited[i]=false;
	}
	
}

void Solution(){
	visited[0]=true; //순서 정한 선수는 방문 체크 
	order[3]=0; 
	DFS(0); //order는 0번째부터 다시 확인  
	cout<<ans<<endl;
}

void Solve(){
	Input();
	Solution();
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	Solve();
	return 0;
}
