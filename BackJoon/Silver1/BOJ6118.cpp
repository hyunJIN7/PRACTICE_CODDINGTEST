#include <bits/stdc++.h>
#define MAX 20001
using namespace std;


int N,M; // ���, ���� ��

vector<int> v[MAX]; 
bool visited[MAX]={0,};
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >>N>>M;
	while(M--){
		int s,e;
		cin>>s>>e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	
	visited[1]=true;
	queue<pair<int,int>> q;
	q.push({1,0});
	vector<int> candi;
	int maxD = 0;
	while(!q.empty()){
		int cN = q.front().first;
		int cD = q.front().second;
		q.pop();
		
		
		if(cD > maxD){
			maxD = cD;
			candi.clear();
			candi.push_back(cN);
		}
		else if(cD == maxD) candi.push_back(cN);

		for(auto e : v[cN]){
			if(!visited[e]){
				q.push({e,cD+1});
				visited[e]=true;
			}
			
		}
	}
	sort(candi.begin(),candi.end() );
	// ��� : �갣 ��ȣ , �Ÿ�, ���� �갣 �� 
	cout<< candi[0]<<" "<<maxD<< "  " <<candi.size();

	
}
