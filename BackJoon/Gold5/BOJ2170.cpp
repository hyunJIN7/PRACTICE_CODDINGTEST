#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,answer=0;
	cin >> n;
	vector<pair<int,int>> v;
	for(int i = 0 ; i < n ; i++){
		int s,e;
		cin >>s>>e;
		v.push_back({s,e});		
	}
	sort(v.begin(),v.end());
	
	int s = v[0].first, e=v[0].second;
	for(int i = 1 ; i < n ; i++){
		int from= v[i].first,to=v[i].second;
		if(from <= e){ // start ���� ���������ϱ� �̰͸� �˻�  
			e = (to > e)?to:e;
		}
		else{//�Ȱ�ġ�� ��� 
			answer+= (e-s);
			s=from;
			e=to;
		}		
	}
	answer+= (e-s);
	cout<<answer;
}
