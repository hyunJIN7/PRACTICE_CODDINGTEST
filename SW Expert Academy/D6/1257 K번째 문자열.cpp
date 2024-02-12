#include<iostream>
#include <cstring>
#include <vector>
#define MAX_LEN 400
#define OFFSET 'a'
#define M 26
using namespace std;

int K; 
vector<char> vec(MAX_LEN);

struct Trie{
	bool is_terminal;
	Trie* child[M];
	Trie(){
		is_terminal = false;
		for(int i = 0; i < M; i++) child[i] = NULL;
	}
	void Insert(char *str){
		if(*str == NULL){ //문자열의 끝 
			is_terminal = true;
			return;
		}
		int idx = *str - OFFSET;
		if(child[idx] == NULL) child[idx] = new Trie();
		child[idx]->is_terminal = true; //이 문제에서만 
		child[idx]->Insert(str + 1);
	}
	void IsSorting(Trie *node, int idx){
		if(node->is_terminal){
			K--;
			if(!K){
				for(char c : vec) cout << c;
				cout<<"\n";
				return;	
			} 
		}
		if(K <= 0) return;
		for(int i = 0 ; i < M ; i++){
			if(child[i] == NULL) continue;
			vec.push_back(OFFSET + i);
			child[i]->IsSorting(child[i], idx + 1);
			vec.pop_back();
		}
	}
	
};

int main(int argc, char** argv)
{
	int T;
	cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case)
	{
		vec.clear();
		char str[MAX_LEN + 1];
		cin >> K;
		cin >> str;
		Trie* root = new Trie();
		for(int i = 0 ; str[i] != '\0'; i++){ 
			root->Insert(str + i); 
		}
		cout<<"#"<<test_case<<" ";;
		root->IsSorting(root,0);
		if(K > 0) cout <<"none\n";
	}
	return 0;
}
