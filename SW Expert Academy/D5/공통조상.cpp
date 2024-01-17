#include <bits/stdc++.h>

#define MAX 10000

using namespace std;

struct node{
	int num;
	int sub;
	vector<node*> child;
	node* parent;
	node(){
		sub = 1;
	}
	node(int num){
		this->num = num;
		sub = 1;
	}
};

int v, e, a, b;
node* tree[MAX];
bool visited[MAX];

int getSub(node* parent);
node* findAncestor(node* n1, node* n2);

node* newNode(int num){
	tree[num] = new node(num);
	return tree[num];
}


void init(){
	memset(visited, 0, sizeof(visited));
	memset(tree, 0, sizeof(tree));
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		init();
		cin >> v >> e >> a >> b;
		while(e--){
			int par,ch;
			cin >> par >> ch;
			if(tree[par] == NULL) newNode(par); 
			if(tree[ch] == NULL) newNode(ch); 
			
			tree[par]->child.push_back(tree[ch]);
			tree[ch]->parent = tree[par];
		}
		getSub(tree[1]);
//		memset(visited, 0, sizeof(visited));
		node* ancestor = findAncestor(tree[a], tree[b]);
		cout << "#" << test_case << " "<<  ancestor->num << " " <<ancestor->sub<<"\n";
	}
	return 0;
}

int getSub(node* parent){
	if(parent->child.size()==0) return 1;
	for(int i = 0 ; i < parent->child.size(); i++){
		parent->sub += getSub(parent->child[i]);
	}
	return parent->sub;
}

node* findAncestor(node* n1, node* n2){
	if(n1->num == n2->num) return n1;
	visited[n1->num] = true;
	visited[n2->num] = true;
	
	node* root = n1->parent;
	
	while(root != NULL){
		if(visited[root->num]){
			return root;
		}
		visited[root->num] = true;
		root = root->parent;
	}
	root = n2->parent;
	while(root != NULL){
		if(visited[root->num]){
			return root;
		}
		visited[root->num] = true;
		root = root->parent;
	}
}
