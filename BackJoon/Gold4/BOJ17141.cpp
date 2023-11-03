#include <bits/stdc++.h>

#define MAX_N 50
#define MAX_M 10
#define VIRUS 2
#define WALL 1
#define DIR_NUM 4

using namespace std;

typedef pair<int,int> pii;

int N, M;

int lab[MAX_N][MAX_N];

vector<pii> can_virus;
int select_virus[MAX_N];
int target = 0; //���̷��� ��Ʈ�����ϴ� ��ġ ����  
int visited_time[MAX_N][MAX_N];

int ans = INT_MAX;

bool InRange(int y,int x){ return 0 <= y && y < N && 0 <= x && x < N;}

int GetMinTime(){
	int min_time = 0 , virus_target = target;
	int dy[DIR_NUM] = {0,0,-1,1};
	int dx[DIR_NUM] = {-1,1,0,0};
	
	queue<pii> que;
	
	for(int i = 0 ; i < M ; i++){
		int y, x;
		tie(y,x) =  can_virus[select_virus[i]];
		que.push({y,x});
		visited_time[y][x] = 1;
		virus_target--;
	}
	
	if(!virus_target) return 0;
	
	while(!que.empty()){
		int y,x;
		tie(y,x) = que.front();
		que.pop();
		
		for(int i = 0 ; i < DIR_NUM; i++){
			int ny = y + dy[i], nx = x + dx[i];
			if(!InRange(ny,nx) || lab[ny][nx] == WALL || visited_time[ny][nx] ) continue;
			//���� ��, ��, �̹� �湮 �� ���� �н�
			virus_target--;
			if(!virus_target) //�ð� 1���� �����ؼ� y,x�� �ð��� ���� 
				return visited_time[y][x] ;
			
			visited_time[ny][nx] = visited_time[y][x] + 1;
			que.push({ny,nx});
			 
		}
	}
	
	// virus_target �� ��ä��ٸ�
	return INT_MAX; 
}

void Backtrack(int start, int depth){
	if(depth == M){
		//�ش� ���̷��� ��ġ ���տ��� 
		memset(visited_time, 0, sizeof(visited_time)); 
		ans = min(ans, GetMinTime()); 
		return;
	}
	
	for(int i = start + 1; i < can_virus.size(); i++){
		//�湮 ǥ�� �ؾ��ϳ� 
		select_virus[depth] = i;
		Backtrack(i, depth + 1);
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ;j < N ; j++){
			cin >> lab[i][j];
			if(lab[i][j] == VIRUS)
				can_virus.push_back({i,j});
			if(lab[i][j] != WALL) target++;
		}
	}

	Backtrack(-1,0);
	if(ans == INT_MAX) ans = -1;
	cout << ans;
	
	return 0;	
}
