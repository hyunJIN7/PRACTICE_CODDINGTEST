#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >>n;
	int left[n];
	vector<int> order; 
	for(int i = 0 ; i < n ;i++) cin>>left[i];
	
	
	for(int i = n-1 ; i>=0 ; i--){
		if(left[i]==0) {
			order.insert(order.begin(), i+1); // �տ� ū�������� �Ǿտ� ����  
			continue; 
		}
		int size = order.size();
		for(int j = 0,c=0 ; j < size; j++ ){
			//������ ū������� üũ 
			if(order[j] > (i+1) ) { //i+1 : Ű 
				c++;
			}
			if(c == left[i]){
				order.insert(order.begin()+j+1, i+1);
				break;
			}
		}

	}
	string ans;
	for(auto e : order) ans=ans + to_string(e)+" ";
	cout<<ans;
}
