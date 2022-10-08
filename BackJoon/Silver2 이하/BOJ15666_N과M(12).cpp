#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

int N,M;
int visited[MAX]={0,};
vector<int> input;
int arr[MAX];

void BackTrack(int depth, int flag){
	if(depth == M){
        for(int i = 0 ; i < M ;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
		return;
	}
	for(int i = 0 ; i < input.size() ; i++){
		if(flag <= input[i]){
		    
		    arr[depth] = input[i];
		    BackTrack(depth+1, input[i]);
		}
	}	
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M;
	for(int i = 0,num ; i < N ;i++){
		cin>>num;
		input.push_back(num);
	}
	sort(input.begin(),input.end());
	input.erase(unique(input.begin(),input.end()),input.end());

	BackTrack(0,0);
	
}
