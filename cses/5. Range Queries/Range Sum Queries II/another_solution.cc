#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10;
int t[4 * N], a[N];

void build(int p, int l, int r) {
    if (l == r) {
        t[p] = a[l];
    } else {
        int m = (l + r) / 2;
        build(p * 2, l, m);
        build(p * 2 + 1, m + 1, r);
        t[p] = t[p * 2] + t[p * 2 + 1];
    }
}

int query(int p, int l, int r, int a, int b) {
    if (l == a && r == b) {
        return t[p];
    } else {
        int m = (l + r) / 2;
        if (b <= m) {
            return query(p * 2, l, m, a, b);
        } else if (a >= m + 1) {
            return query(p * 2 + 1, m + 1, r, a, b);
        } else {
            return query(p * 2, l, m, a, m) + query(p * 2 + 1, m + 1, r, m + 1, b);
        }
    }
}

void update(int p, int l, int r, int k, int x) {
    if (l == r) {
        t[p] = x;
    } else {
        int m = (l + r) / 2;
        if (k <= m) {
            update(p * 2, l, m, k, x);
        } else {
            update(p * 2 + 1, m + 1, r, k, x);
        }
        t[p] = t[p * 2] + t[p * 2 + 1];
    }
}


__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    for (int i = 0; i < q; ++i) {
        int code;
        cin >> code;
        if (code == 1) {
            int k, u;
            cin >> k >> u;
            --k;
            update(1, 0, n - 1, k , u);
        } else {
            int a, b;
            cin >> a >> b;
            --a, --b;
            cout << query(1, 0, n - 1, a, b) << endl;
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
