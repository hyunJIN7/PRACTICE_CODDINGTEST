//https://yabmoons.tistory.com/379
//https://github.com/goragoraki/Data-Structure/blob/main/8.%20Trie/trie.cpp
#include <iostream>
using namespace std;

struct Trie{
	bool Finish;
	Trie *Node[26];
	Trie(){ //생성자 
		Finish = false;
		for(int i = 0 ; i < 26; i++) Node[i] = NULL;	
	}
	~Trie(){ //소멸자  
		for(int i = 0 ; i < 26; i++)
			if(Node[i]) delete Node[i];
	}
	
	void Insert(char *str){
		if(*str == NULL){
			Finish = true;
			return;
		}	
		int curr = *str - 'A';
		if (Node[curr] == NULL) Node[curr] = new Trie(); //업는 곳 이면 새로 생성 
		Node[curr]->Insert(str + 1); // 다음 문자 삽입   
		//구조체의 포인터는 ->로 접근  
		//해당 노드 그 자체의 Insert로 가는 거지 
		// 'ABC'에서 A에서 이 줄을 호출하면 (즉 B를 넘기면)
		// A Node의 Insert를 호출해 B가 있는지 검사하고 이렇게 
	}
	
	void Find(char *str){
		if(str == NULL){   
			return Finish; // 해당 문자열을 찾았다면 true, 아님 false 
//			if (Finish == true) return true; 
//			return false;
		} 		
		int curr = *str - 'A';
		if(Node[curr] = NULL) return false; //노드가 생성되지 않았다면 => trie에 없는 문자자
		return Node[curr]->Find(str + 1); 		
	}
		//생성된 노드들 출력  
	void IsSorting(Trie *N, char str[], int idx){
		if(N->Finish) cout << str << "\n"; //tire의 finish가 true면 출력
		for(int i = 0 ; i < 26; i++){
			
			if(N->Node[i] != NULL){
				char c = i + 'A';
				str[idx] = c;
				N->IsSorting(N->Node[i], str, idx+1);
			}
		}  
	} 
};



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Trie *root = new Trie();
	char *Str[5];
	Str[0] = "ZYX";
	Str[1] = "BCG";
	Str[2] = "ABC";
	Str[3] = "BDE";
	Str[4] = "ABCD";
	
	for(int i = 0 ; i < 5; i++){
		root->Insert(Str[i]);
	}
	for(int i = 0 ; i < 26; i++){
		if(Root->Node[i] != NULL){
			char Str[5] = {NULL};
			Str[0] = i + 'A';
			root->IsSorting(Root->Node[i,Str,1]);
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
