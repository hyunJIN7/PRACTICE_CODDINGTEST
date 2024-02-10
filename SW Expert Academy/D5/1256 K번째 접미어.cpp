#include<iostream>
#define OFFSET 'a'
#define M 26
#define MAX_LEN 400
using namespace std;

struct Trie {
	bool is_terminal;
	Trie* node[M];

	Trie() {
		is_terminal = false;
		for (int i = 0; i < M; i++) node[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < M; i++)
			if (node[i]) delete node[i];
	}

	void Insert(char* str) {
		if (*str == NULL) { // 문자열 끝이라면 
			is_terminal = true;
			return;
		}
		int curr = *str - OFFSET;
		if (node[curr] == NULL)
			node[curr] = new Trie();
		node[curr]->Insert(str + 1);

	}
	bool Find(char* str) {
		if(*str == NULL) return is_terminal;
		int curr = *str - OFFSET;
		if (node[curr] == NULL) return false;
		return node[curr]->Find(str + 1);

	}
	void IsSorting(Trie* N, char str[], int idx, int* cnt) {
		if (N->is_terminal) {
			(*cnt)--;
			if (!(*cnt)){
				cout << str << "\n";
				return;
			}

		}
		if (*cnt <= 0) return;
		for (int i = 0; i < M; i++) {
			if (N->node[i] == NULL) continue;
			str[idx] = i + OFFSET;
			N->IsSorting(N->node[i], str, idx + 1, cnt);
			str[idx] = NULL;
		}
	}

};

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		char str[MAX_LEN + 1];
		cin >> str;
		Trie* root = new Trie();
		for (int i = 0; str[i] != '\0'; i++) {
			root->Insert(str + i);
		}
		cout << "#" << test_case << " ";
		str[MAX_LEN + 1] = {NULL};
		root->IsSorting(root, str, 0, &N);
	}
	return 0;
}
