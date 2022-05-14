#include <iostream>
#define MAX 1000000000
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll x,y;
	cin>>x>>y;
	int z = y*100/x;
	if( z >= 99){
		cout<<"-1"; return 0;
	}

	ll low=0,high=MAX;
	while(low <= high){
		ll mid = (low + high)/2;
		int new_z = (y+mid)*100/(x+mid);
		if(new_z>z) high = mid-1;
		else low = mid+1;
	}
	cout<<low;
}
/*
ÀÌºÐÅ½»ö 
while(l<=h) <¾Æ´Ñ <= ÇØÁà¾ßÇÔ. 

*/
