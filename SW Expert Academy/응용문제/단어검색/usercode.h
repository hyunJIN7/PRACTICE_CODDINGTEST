#include <vector>
#define OFFSET 'a'
#define M 26
using namespace std;

struct Trie {
	bool removed;
	int cnt; // 양수면 terminal
	Trie* child[M];
	Trie() {
		removed = false;
		cnt = 0;
		for (int i = 0; i < M; i++) child[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < M; i++) delete child[i];
	}

	int add(Trie* node, const char* str) {
		if (*str == NULL) {
			if (node->removed) {
				node->removed = false;
				node->cnt = 0;
			}
			return ++(node->cnt);
		}
		int curr = *str - OFFSET;
		if (node->child[curr] == NULL)
			node->child[curr] = new Trie();
		return node->add(node->child[curr], str + 1);
	}

	int search(Trie* node, const char* str, int* total, const bool del) {
		if (*str == NULL) {
			int new_cnt = node->cnt;
			if (del) {
				node->cnt = 0;
				node->removed = true;
			}
			*total += new_cnt;
			return new_cnt;
		}
		for (int i = 0; i < M; i++) {
			if (node->child[i] == NULL) continue;
			if (i == *str - OFFSET) {
				i = *str - OFFSET;
				if (node->child[i] == NULL) continue;
				node->search(node->child[i], str + 1, total, del);
			}
			else if (*str == '?') node->search(node->child[i], str + 1, total, del);
			else continue;
		}
		return *total;
	}

};

Trie* root = NULL;

void init() {
	if (root != NULL) delete root;
	root = new Trie();
	return;
}

int add(char str[]) {
	return root->add(root, str);
}

int remove(char str[]) {
	int total = 0;
	return root->search(root, str, &total, true);
}

int search(char str[]) {
	int total = 0;
	return root->search(root, str, &total, false);
}
