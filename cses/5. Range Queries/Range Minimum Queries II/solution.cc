#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10, INF = 1e9 + 10;
int n, a[N], t[4 * N];

void build(int p, int l, int r) {
    if (l == r) {
        t[p] = a[l];
    } else {
        int m = (l + r) / 2;
        build(p * 2, l, m);
        build(p * 2 + 1, m + 1, r);
        t[p] = min(t[p * 2], t[p * 2 + 1]);
    }
}

int query(int p, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) return t[p];
    int m = (l + r) / 2;
    if (qr <= m) {
        return query(p * 2, l, m, ql, qr);
    } else if (ql >= m + 1) {
        return query(p * 2 + 1, m + 1, r, ql, qr);
    } else {
        return min(query(p * 2, l, m, ql, m), query(p * 2 + 1, m + 1, r, m + 1, qr));
    }
}

void update(int p, int l, int r, int x, int v) {
    if (l == r) {
        t[p] = v;
    } else {
        int m = (l + r) / 2;
        if (x <= m) {
            update(p * 2, l, m, x, v);
        } else {
            update(p * 2 + 1, m + 1, r, x, v);
        }
        t[p] = min(t[p * 2], t[p * 2 + 1]);
    }
}

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    build(1, 0, n - 1);
    for (int i = 0; i < q; ++i) {
        int c;
        cin >> c;
        if (c == 1) {
            int k, u;
            cin >> k >> u;
            update(1, 0, n - 1, k - 1, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 0, n - 1, a - 1, b - 1) << endl;
        }
    }

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
