// map : https://blockdmask.tistory.com/87 
// substr : https://modoocode.com/235
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	ll n,ans=1;
	cin>>n;
	string sid[n]; // ���ڿ� ���̰� 100 ���Ϸ� ���ͼ� ll�� ���� �Ұ�  
	for(int i = 0 ; i <  n ; i++) {
		cin>>sid[i];
	}
	int len = sid[0].length();
	
	for(;ans<=len ; ans++){ // ���� n���� ���������� �ϸ� Ʋ��  
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
