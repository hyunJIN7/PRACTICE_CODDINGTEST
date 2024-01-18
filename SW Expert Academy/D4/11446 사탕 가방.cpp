#include<iostream>

using namespace std;

#define MAX_N 101
typedef long long ll;

int N;
ll M, MAX = 0;
ll arr[MAX_N];

ll binarySearch(){
	ll left = 1, right = MAX;//arr[N-1];
	ll ans = 0, sum = 0;
	while(left <= right){
		ll mid = left + (right - left) / 2;
		sum = 0;
		for(int i = 0 ; i < N ; i++) sum += (arr[i] / mid);
		if(sum >= M){
			ans = mid;
			left = mid + 1; 
		}
		else right = mid - 1;
	}
	return ans;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		for(int i = 0; i < N; i++){
			cin >> arr[i];
			(MAX < arr[i])? MAX = arr[i]  : 1 ;
		}
		cout << "#" << test_case<< " " << binarySearch() << "\n";
	}
	return 0;
}
