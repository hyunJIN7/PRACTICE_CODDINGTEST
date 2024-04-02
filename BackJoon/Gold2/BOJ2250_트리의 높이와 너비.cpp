#include <iostream>
#include <vector>
#include <cstring>
#define MAX_N 10000
#define EMPTY -1
using namespace std;

int N;

int ch[MAX_N+1][2];
int from[MAX_N + 1],to[MAX_N + 1]; // 범위
int par[MAX_N + 1];
int root = 0;
int col = 1;

void DFS(int node, int level) {
    if (ch[node][0] != EMPTY)
        DFS(ch[node][0], level+1);

    from[level] = min(from[level], col);
    to[level] = max(to[level], col);
    col++;
    if (ch[node][1] != EMPTY)
        DFS(ch[node][1], level + 1);
}

void FindRoot() {
    int c = 1;//아무거나 잡아서
    int p = par[c];
    while (p) { //부모가 0 나올 때 까지 
        c = p;
        p = par[c];
    }
    root = c;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(from, 0x3f, sizeof(from));

    cin >> N; 
    for (int i = 0; i < N; i++) {
        int p, l, r;
        cin >> p >> l >> r;
        ch[p][0] = l;
        ch[p][1] = r;
        par[l] = par[r] = p;
    }
    FindRoot();
    DFS(root,1);

    int max_w = -1, max_level = 0;
    for (int i = 1; i <= N; i++) {
        if (max_w < to[i] - from[i]) {
            max_w = to[i] - from[i];
            max_level = i;
        }
    }
    cout << max_level<<" " << max_w + 1;
    return 0;
}
