#include <bits/stdc++.h>

#define MAX 1002
#define PLUS -1
#define MINUS -2
#define MULTIPLY -3
#define DIVIDE -4
#define EMPTY 0


using namespace std;

int N;

struct node{
	float num;
	int op;
	node* left;
	node* right;
};

node* newNode(){
	node* new_node = new node;
	new_node->num = new_node->op = EMPTY;
	new_node->left = new_node->right = NULL;
	return new_node;
}

node* tree[MAX];

float calculate(node* root) {
	if(root->op != EMPTY){ // 연산자 
		int left =  calculate(root->left);
		int right = calculate(root->right);
		
		int res, op = root->op;
		if (op == PLUS) res = left + right;
		else if (op == MINUS) res = left - right;
		else if (op == MULTIPLY) res = left * right;
		else if (op == DIVIDE) res = left / right;
		root->num = res;
		return res;
	}
	return root->num;	
}

vector<string> split(string str, char deli) {
	istringstream iss(str);
	string buffer;
	vector<string> res;
	while (getline(iss, buffer, deli))
		res.push_back(buffer);
	return res;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 10;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		string line;
		cin.ignore();
		
		for (int i = 1; i <= N; i++) {
			getline(cin, line);
			vector<string> line_split = split(line, ' ');
			int idx = stoi(line_split[0]);
			if(tree[idx] == NULL) tree[idx] = newNode(); 
		
			if (line_split[1] == "+") tree[idx]->op = PLUS;
			else if (line_split[1] == "-") tree[idx]->op = MINUS;
			else if (line_split[1] == "*") tree[idx]->op = MULTIPLY;
			else if (line_split[1] == "/") tree[idx]->op = DIVIDE;
			else{ //숫자인 경우 
				tree[idx]->num = stof(line_split[1]);
				continue;
			}
			//자식이 있는 경우  
			int left = stoi(line_split[2]), right = stoi(line_split[3]);
			tree[idx]->left = tree[left] = newNode();
			tree[idx]->right = tree[right] = newNode();
		}
		cout << "#" << test_case << " "<< (int)calculate(tree[1])<<"\n";
	}
	return 0;
}
