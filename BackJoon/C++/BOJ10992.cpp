//�����17 
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	if(n<1 || n>100)
		return 0;
		
	for(int i = 0 ; i < n ; i++){
		//cout<<"i : "<<i<<"\n";
		for(int j = i ; j < n-1 ;j++){
			cout<<" ";
		}
		
		
		for(int k=0; k < 2*(i+1) - 1; k++ ){
			//cout<<"k : "<<k<<"\n";
			if(i == 0 || i == n-1){
				cout<<"*";
			}
			else{
				if(k==0 || k== 2*(i+1) - 2 ){
					cout<<"*";
				}
				else{
					cout<<" ";
				}
			}				
		}
		
		cout<<"\n";	
	}	
	return 0;
}
