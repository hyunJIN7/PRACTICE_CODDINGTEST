#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

#define N_MAX 500000

using namespace std;
int N;

vector<pair<int,int> > edge[N_MAX];
int pre_cost[N_MAX]; 
long long accu_cost[N_MAX];
bool visited[N_MAX];


long long solve(){
	queue<int> q; //현재 노드 번호
	int curr_node = 0;
	q.push(curr_node);  
	pre_cost[curr_node] = accu_cost[curr_node] = 0;

	while(!q.empty()){
		curr_node = q.front(); 
		q.pop();
		for(pair<int,int> e : edge[curr_node]){
			long long next_cost = accu_cost[curr_node] + e.second;

			if(next_cost == accu_cost[e.first]){
				if( e.second  < pre_cost[e.first])
					pre_cost[e.first] = e.second; 
			}
			else if(next_cost < accu_cost[e.first]){
				q.push(e.first);
				pre_cost[e.first] = e.second;
				accu_cost[e.first] = next_cost;
			}
	
		}
	}
	long long ans = 0;
	for(int i = 0 ; i < N ; i++) ans += pre_cost[i];
	return ans;
}

int main(int argc, char** argv)
{
	int T;
	cin>>T;

	for(int test_case = 1; test_case <= T; ++test_case)
	{
		int M;
		cin >> N >> M;
		for (int i = 0; i < N; i++) edge[i].clear();
		fill(pre_cost, pre_cost + N, INT_MAX);
		fill(accu_cost, accu_cost + N, LONG_MAX);

		while(M--){
			int from,to,c;
			cin >> from >> to >> c;
			edge[--from].push_back({--to, c});
			edge[to].push_back({from,c});
		}
		cout<<"#"<<test_case<<" "<<solve()<<"\n";
	}
	return 0;
}
