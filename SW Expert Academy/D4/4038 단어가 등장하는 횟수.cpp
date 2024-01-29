#include<iostream>
#include <vector>
#include <string>

using namespace std;

vector<int>findPattern(string pattern) {
	int n = pattern.size();
	vector<int> pi(n, 0);

	for (int i = 1, j = 0; i < n; i++) {

		while (j && pattern[i] != pattern[j]) {
			j = pi[j - 1];
		}

		if (pattern[i] == pattern[j])
			pi[i] = ++j;

	}

	return pi;
}

int kmp(string str, string pattern) {
	int n = str.size(), m = pattern.size();
	int ans = 0;
	vector<int> pi = findPattern(pattern);
	for (int i = 0, j = 0; i < n; i++) {

		while (j && str[i] != pattern[j]) {
			j = pi[j - 1];
		}

		if (str[i] == pattern[j]) {
			if (j == m - 1) {
				ans++;
				j = pi[j];
			}
			else {
				j++;
			}
		}

	}

	return ans;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		string str, pattern;
		cin >> str >> pattern;
		cout << "#" << test_case << " " << kmp(str, pattern) << "\n";

	}
	return 0;
}
