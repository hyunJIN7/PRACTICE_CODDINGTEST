#include <bits/stdc++.h>

using namespace std;

int N, M;


int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> N >> M;
	
	map<string,string> m;
	 
	while(N--){
		string site,pw;
		cin >> site >> pw;
		m[site] = pw;
	}

	while(M--){
		string site;
		cin >> site;
		cout<< m[site]<<"\n";
	}
	
	return 0;	
}
