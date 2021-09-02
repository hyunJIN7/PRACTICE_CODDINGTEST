#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<int> v,cv;
	for(int i = 0,tmp ; i < n ; i++){
		cin>>tmp;
		v.push_back(tmp);
	}
	cv.assign(v.begin(),v.end());  
 
	sort(cv.begin(),cv.end());
	cv.erase(unique(cv.begin(),cv.end()), cv.end() ); 
	string answer;	
	for(int i = 0 ; i < n ; i++){
		auto it = lower_bound(cv.begin(),cv.end(), v[i]);
		answer += (to_string( it-cv.begin() ) +" " );	
	}

	cout<<answer;
}
