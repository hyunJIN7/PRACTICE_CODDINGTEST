#include <bits/stdc++.h>

#define MAX_N 1<<19
using namespace std;
typedef long long ll;

int N ,Q;
int base = 1;
ll tree[MAX_N];

void init() {
    for (int i = 0; i < N; i++)
        cin >> tree[base + i];
    for (int i = base - 1; i; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

void update(int node, ll val) {
    tree[node+=base] = val;
    for (node >>= 1; node; node >>= 1)
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int qs,int qe) {
    ll ret = 0;
    if (qe < qs) swap(qe, qs);
    for (qs += base, qe += base; qs <= qe; qs >>= 1, qe >>= 1) {
        if (qs % 2 == 1) 
            ret += tree[qs++];
        if (qe % 2 == 0) 
            ret += tree[qe--];    
    }
    return ret;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    while (base < N) base <<= 1;
    
    init();
    while (Q--) {
        int qs, qe, node; ll val;
        cin >> qs >> qe >> node >> val;
        cout << query(qs-1, qe-1)<<"\n";
        update(node - 1, val);
    }
    return 0;
}
