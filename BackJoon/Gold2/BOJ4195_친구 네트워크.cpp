#include <unordered_map>
#include <iostream>

#define MAX_N 2000001
using namespace std;

int TC, F;
unordered_map<string, int> um;
int par[MAX_N];
int cnt[MAX_N];

int Parent(int a) {
    if (par[a] == a) return a;
    return par[a] = Parent(par[a]);
}

int Union(int a, int b) {
    a = Parent(a);
    b = Parent(b);
    if (a != b) {
        par[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 1;//???
    }
    return cnt[a];
}


void init() {
    um.clear();
    for (int i = 1; i <= 2 * F; i++) {
        par[i] = i;
        cnt[i] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> TC;
    while (TC--) {
        cin >> F;
        init();
        int n = 0;
        while (F--) {
            string a, b;
            cin >> a >> b;
            int aid = um[a], bid = um[b];
            if (!aid) aid = um[a] = ++n;
            if (!bid) bid = um[b] = ++n;
            cout << Union(aid, bid) << "\n";
        }
    }
    return 0;
}
