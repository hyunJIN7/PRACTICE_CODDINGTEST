/*
  - 투포인터, 같은 위치에서 시작하고
  sum < p : 일때도 남은 여분이랑 같이 더해서 ans와 비교해야함

  5 10
  1 100 101 102 200 => 이 케이스
  
*/
#include<iostream>
#include <cstring>
#define MAX 200002
using namespace std;

int n,p,ans;
int arr[MAX];
int offDay[MAX]; 

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie();cout.tie();
	int T;
	cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n >> p;
		
		ans = 0;		
		memset(offDay,0,sizeof(offDay));
		
		cin>> arr[0];
		for(int i = 1 ; i < n; i++){
			cin >> arr[i];	
			offDay[i] = offDay[i-1] + arr[i] - arr[i-1] - 1; 
			//공부 안한 일 수 누적  기록 
		} 

		int left = 0, right = 0, sum; // -> <- 방향만  
		while(left <= right && right < n){
			sum = offDay[right] - offDay[left];
			if(sum == p){
				//오른쪽으로 더 가야해  
				ans = max( arr[right] - arr[left] + 1, ans);
				right++;
			}
			else if(sum > p)left++;	
			else if(sum < p){	
				ans = max(arr[right] - arr[left] + 1 + p - sum , ans);
				right++;	
			}
		} 
		cout<<"#"<<test_case<<" "<<ans<<"\n";	
	}
	return 0;
}
