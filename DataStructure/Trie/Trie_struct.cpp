//https://yabmoons.tistory.com/379
//https://github.com/goragoraki/Data-Structure/blob/main/8.%20Trie/trie.cpp
#include<iostream>
#define OFFSET 'a'
#define M 26
struct Trie{
	
	bool is_terminal;
	Trie* child[M];
	Trie(){
		is_terminal = false;
		for(int i = 0; i < M; i++) child[i] = NULL;
	}
	~Trie(){
		for(int i = 0; i < M; i++) delete child[i];
	}
	
	void Insert(char *str){
		if(*str == NULL){ //문자열의 끝 
			is_terminal = true;
			return;
		}
		int idx = *str - OFFSET;
		if(child[idx] == NULL) child[idx] = new Trie();
		child[idx]->Insert(str + 1);
	}
	bool Find(char *str){
		if(*str == NULL) return is_terminal;
		int idx = *str - OFFSET;
		if(child[idx] == NULL) return false;
		return child[idx]->Find(str + 1);
	}
	void IsSorting(Trie *node, char str[], int idx){
		if(node->is_terminal){
			cout << str;
			
			return;
		}
		
		for(int i = 0 ; i < M ; i++){
			if(child[i] == NULL) continue;
			str[idx] = OFFSET + i;
			child[i]->IsSorting(child[i],str,idx+1);
		}
		
		
	}
	
};


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Trie *root = new Trie();
	char *String[5];
	String[0] = "ZYX";
	String[1] = "BCG";
	String[2] = "ABC";
	String[3] = "BDE";
	String[4] = "ABCD";
	
	for(int i = 0 ; i < 5; i++){
		root->Insert(String[i]);
	}
	for(int i = 0 ; i < 26; i++){
		if(Root->Node[i] != NULL){
			char Str[5] = {NULL};
			Str[0] = i + 'A';
			root->IsSorting(root->Node[i],Str,1);
		}
	}
	
	
}

/*
#include <iostream>
#define MAXN 10000000
using namespace std;

struct Trie{
    bool end;
    Trie *next[26];
    
    Trie* Alloc(){
        for (int i = 0; i < 26;i++)
            next[i] = NULL;
        end = false;
        return this;
    }

};

Trie root;
Trie node_pool[MAXN];
int node_cnt;

void init(){
    root.Alloc();
    node_cnt = 0;
}

void insert(char* s){
    Trie *node = &root;
    int idx = 0;
    while(!s[idx]){
        int id = s[idx] - 'a';
        if(!node->next[id])
            node->next[id] = node_pool[node_cnt++].Alloc();
        node = node->next[id];
    }
    node->end = true;
}
void remove(char* s){
    Trie *node = &root;
    int idx = 0;
    while(!s[idx]){
        int id = s[idx] - 'a';
        if(!node->next[id])
            node = node->next[id];
        else
            return;
    }
    node->end = false;
}
bool find_str(char* s){
    Trie *node = &root;
        int idx = 0;
        while(!s[idx]){
            int id = s[idx] - 'a';
            if(!node->next[id])
                node = node->next[id];
            else
                return false;
        }
        if(node->end) 
            return true;
        else
            false;
}

int main(){
    init();
    char s[] = "monset";
    insert(s);
    cout << find_str(s) << '\n';
    remove(s);
    cout << find_str(s) << '\n';
    return 0;
}
	*/
