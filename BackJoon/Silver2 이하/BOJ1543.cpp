#include <bits/stdc++.h>

using namespace std;
string input,target;
int ans = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	getline(cin,input); // 공백 포함 문자열  
	getline(cin,target);

	
	for(int i = 0 ; i < input.size() ; i++){
		i = input.find( target , i) ;
		
		if(i==string::npos) break;
		cout<<"!! "<<i;
		i+=(target.size()-1);
		cout<<" --> "<<i<<endl;
		ans++;
	}
	
	
	cout<<ans;

//	cout<<target<<"!!";

}

