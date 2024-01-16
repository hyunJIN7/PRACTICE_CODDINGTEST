#include<iostream>
#include <stack>
#include <string>
#include <vector>

#define MAX 105
using namespace std;

int N;
char tree[MAX];
void inorder(int num) {
	if (num > N) return;
	inorder(num * 2);
	cout << tree[num];
	inorder(num * 2 + 1);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 10;
	//cin >> T
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		string line;
		cin.ignore();
		for (int i = 1; i <= N; i++) {
			getline(cin, line);
			tree[i] = line[line.find(' ') + 1];
		}

		cout << "#" << test_case << " ";
		inorder(1);
		cout << "\n";

	}
	return 0;
}
