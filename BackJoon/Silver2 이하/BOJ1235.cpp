// map : https://blockdmask.tistory.com/87 
// substr : https://modoocode.com/235
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	ll n,ans=1;
	cin>>n;
	string sid[n]; // 문자열 길이가 100 이하로 들어와서 ll로 감당 불가  
	for(int i = 0 ; i <  n ; i++) {
		cin>>sid[i];
	}
	int len = sid[0].length();
	
	for(;ans<=len ; ans++){ // 조건 n보다 작은것으로 하면 틀림  
		map<string,int> m;
		bool isOverlap= false;
		for(int i = 0 ; i < n ; i++){
			string skey = sid[i].substr(len-ans,len);
			if( m.count(skey) ){
				isOverlap = true;
				break; 
			}
			m.insert({skey, 1});
		}
		if(!isOverlap){ 
			cout<<ans;
			break;
		}	
	}
}
