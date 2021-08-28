#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int k;
	cin>>k;
	stack<int> s;
	while(k--){
		int num;
		cin >> num;
		num == 0 ? s.pop() : s.push(num);
	}
	long long sum=0;
	while(s.size()){
		sum+=s.top();
		s.pop();
	}
	cout<<sum;
}
