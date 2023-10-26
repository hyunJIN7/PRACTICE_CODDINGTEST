#include<iostream>
#include <algorithm>

#define MAX 50000

using namespace std;

int N,Q;
int efficiency[MAX];


void Solution(){
	cin >> N >> Q;
}

int main(int argc, char** argv)
{
	cin >> N >> Q;
	for(int i = 0 ; i < N ; i++) cin >> efficiency[i];

	sort(efficiency,efficiency + N);

	while(Q--){
		int target; 
		cin >> target;
		
		int index = lower_bound(efficiency,efficiency + N, target) - efficiency;
		if(index == N || target != efficiency[index]) index = 0;
		cout << index * (N - index - 1) << "\n";

	}

	return 0;
}
