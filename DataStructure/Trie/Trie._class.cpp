#include <iostream>
using namespace std;

class Trie{
	//static은 클래스 변수 ,클래스 함수, 메인 함수 호출 이전에 메모리 공간에 등록
	//초기화 되며 선언된 클래스 내부에 직접 전급 가능
	//생성자에서 초기화 불가  
	static constexpr size_t M = 26;
	static constexpr char OFFSET = 'a'; 
	struct TrieNode{
		int child[M]; // nodes에서 해당 자식 노드가 어디에 위치하는지  
		bool is_termial;
		TrieNode(){
			std::memset(child,-1,sizeof(int)*M);
			is_terminal = false;
		}
	};
	
	std::vector<TrieNode> nodes; // 모든 TrieNodes 한 곳에 넣나봐  
	
public:
	Trie() : nodes(1){} //생성자로 루트 하나 생성해준건가 
	void init(){
		nodes.resize(1);
		nodes[0] = TrieNodes();
	}
	
	void insert(const std::string& str){
		int idx = 0; // nodes에서 index로 0은 root 
		for(const auto& c : str){ // root에서 시작해 idx로 자식들 관리  
			if(nodes[idx].child[c - OFFSET] == -1){//없다면 
				nodes[idx].child[c - OFFSET] = nodes.size(); // c-OFFSET의 nodes에서 인덱스 의미  
				nodes.emplace_back(); 
			}
			idx = nodes[idx].child[c - OFFSET]; //c에 해당하는  자식 위치  
		}
		node[idx].is_terminal = true;
	}
	
	void remove(const std::string& str){
		int idx = 0;
		for(const auto&c : str){
			idx = nodes[idx].child[c - OFFSET];
			if(idx == -1) return;
//			idx = nodes[idx].child[c - OFFSET];
		}
		nodes[idx].is_terminal = false; //맨 끝에 꺼면 false 해주면 됨. 그럼 없는 존재.  
		// 뭐 그 하위의 child의 인덱스 처리 안해도 됨.
		// 어차피 이게 다시 생성된다 해도 nodes에 아예 새로운 노드로 다시 생김 
		// 접근할 일이 없어. 
		// 근데 이거 직전 노드에서 자식 -1은 안해주나????!!!???!?!?!?
		// 음 근데 어차피 안해도 될거 같다.
		// terminal false 만 해줘도 어차피 find 할때 최종적으로 terminal 확인하니까.
		// vector에 새로 생성 되지 않고 기존 거 활용도 하고 이게 최선 
	}
	bool find(const std::string& str) const{
		int idx = 0;
		for(const auto& c : str){
			idx = nodes[idx].child[c - OFFSET];
			if(idx == -1) return false;
		}
		return nodes[idx].is_terminal;
	}
	
};


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


	
}















