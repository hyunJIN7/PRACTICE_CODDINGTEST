#include<iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		unordered_map<string, int> m;
		int N, M;
		cin >> N >> M;
		string str;
		int ans = 0;
		while(N--){
			cin >> str;
			m[str]++;
		}
		while(M--){
			cin >> str;
			if (m[str])	 ans++;
		}
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}
