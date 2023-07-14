#include <bits/stdc++.h> 
#define MAX 1000000000
int fibo[50]={0,1,0,}; // MAX값 위해 인덱스 45 정도면 문제 없다고 한다.  

using namespace std; 

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	for (int i = 2; i < 50; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	
	int N=1;
	cin>>N;

	while(N--){
		int target;
		cin>>target;
		vector<int> ans;
		for(int i =45 ; i>=0 && target;i--){
			if(fibo[i]<=target){
//				cout<<"!!! "<<target<<"  "<<fibo[i]<<endl;
				target-=fibo[i];
				ans.push_back(fibo[i]);
			}
			
		}
		for(int i = ans.size()-1; i>=0 ;i--){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		
	}

	
	
}
