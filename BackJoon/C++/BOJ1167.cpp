#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

vector<pair<int,int>> graph[MAX];
bool check[MAX]={0,};
int V,maxDist=0,maxNode=0;

//��� 
void dfs(int node,int dist){
	if(check[node]) return ; //�̹� �湮�� �� �� 
	
	if(dist > maxDist){
		maxDist = dist;
		maxNode = node;
	}
	for(auto e : graph[node]){
		dfs(e.first,e.second + dist);
	} 
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin>>V;
	for(int i = 1,dist,to, n ; i <= V ; i++){ 
		cin>>n;
		while(true){
			cin>>to;
			if(to==-1) break;
			cin>>dist;
			graph[n].push_back({to,dist});
		}
	}
	
	//������ �������� ���� �� ���� ã�� : ���� �ܰ��� ���� ã�� 
	dfs(4,0);
	memset(check,0,sizeof(check));
	maxDist=0;
	//���� �ܰ��� �������� �ٽ� dfs ������ Ʈ���� ���� ã�� 
	dfs(maxNode,0);
	cout<<maxDist;
	return 0;
}
