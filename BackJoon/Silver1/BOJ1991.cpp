#include <bits/stdc++.h>

#define EMPTY '.'
#define PRE 0
#define IN 1
#define POST 2

using namespace std;

int N;
struct node{ int left,right;};
map<int,node> tree;

void TreeTraversal(int root, int mode){
	if(mode == PRE) cout << (char)root;
	
	if(tree[root].left != EMPTY)
		TreeTraversal(tree[root].left, mode);
		
	if(mode == IN) cout << (char)root;
	
	if(tree[root].right != EMPTY)
		TreeTraversal(tree[root].right,mode);
	
	if(mode == POST) cout << (char)root;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> N;

	for(int i = 0 ; i < N ; i++){
		char root,left,right;
		cin >> root >> left >> right;
		tree[root] = {left,right};
	}
	for(int i = 0 ; i < 3; i++){
		TreeTraversal('A',i);
		cout << "\n";
	}
	
	return 0;
}
