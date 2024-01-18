#include<iostream>
#include <queue>
#include <utility>
#include <tuple>
#define MAX_N 10
using namespace std;

typedef pair<int,int> pii;

int N, K; 
int arr[MAX_N];
int ans;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;

	for(int test_case = 1; test_case <= T; ++test_case)
	{	
		cin >> N;
		for(int i = 0 ; i < N; i++) cin >> arr[i];
		cin >> K;
		ans = K;
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		
		pq.push({0,K});
		while(!pq.empty()){
			int cnt,num;
			tie(cnt, num) = pq.top();
			pq.pop();
			
			if(!num){
				ans = cnt;
				break;
			}
			
			for(int i = 0 ; i < N ; i++){
				pq.push({cnt + num % arr[i] , num / arr[i]});
			}	
		}
		cout <<"#"<<test_case<<" "<<ans<<"\n";
	}
	return 0;
}
