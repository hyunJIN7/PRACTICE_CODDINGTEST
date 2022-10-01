#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

int N,M;
int input[MAX];
bool visited[MAX]={0,};
int arr[MAX];

void BackTrack(int depth){
	if(depth == M){
		for(int i = 0 ; i < M ;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	int flag = 0;
	for(int i = 0 ; i < N ;i++){
		if(!visited[i] && flag != input[i]){
			if(depth){
				if(arr[depth-1] > input[i]) continue;
			}
			visited[i]=true;
			flag = arr[depth] = input[i];
			BackTrack(depth+1);
			visited[i]=false;
			
		}
	}


}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i= 0; i < N ;i++)cin>>input[i];
	
	sort(input,input+N);
	BackTrack(0);	
}
