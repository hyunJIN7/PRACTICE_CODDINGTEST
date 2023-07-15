#include <bits/stdc++.h> 

using namespace std; 

int N,M;//과목수,마일리지  
vector<int> classM;
int ans=0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i = 0 ; i < N ; i++){
		int p,l;
		cin>>p>>l;
		vector<int> people(p);
		for(int i = 0 ; i < p ; i++){
			cin>>people[i];
		}
		sort(people.rbegin(),people.rend());
		if( p < l || !people[l-1])
			classM.push_back(1);
		else classM.push_back(people[l-1]);
	}
	
	sort(classM.begin(),classM.end());
	
	for(auto e: classM){
		if(M>=e){
			ans++;
			M-=e;
		}
		else break;	
	}
	cout<<ans;
}
