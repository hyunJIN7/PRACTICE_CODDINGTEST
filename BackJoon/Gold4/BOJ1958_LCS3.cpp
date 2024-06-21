#include <iostream>
#define MAX_N 102
using namespace std;

int lcs[MAX_N][MAX_N][MAX_N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string a, b, c;
	cin >> a >> b >> c;

	int len1 = a.size();
	int len2 = b.size();
	int len3 = c.size();

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			for (int k = 1; k <= len3; k++) {

				if (a[i-1] == b[j-1] && a[i-1] == c[k-1]) {
					lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
				}
				else {
					lcs[i][j][k] = max(max(lcs[i - 1][j][k], lcs[i][j - 1][k]), lcs[i][j][k - 1]);
				}

			}
		}
	}
	cout << lcs[len1][len2][len3];

	return 0;
}

