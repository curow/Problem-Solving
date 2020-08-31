#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10;
int t[N], a[N];
int n;

void add(int k, int x) {
    a[k] += x;
    while (k <= n) {
        t[k] += x;
        k += k & -k;
    }
}

void update(int k, int u) {
    add(k, u - a[k]);
}

int sum(int k) {
    int s = 0;
    while (k >= 1) {
        s += t[k];
        k -= k & -k;
    }
    return s;
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
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        update(i, x);
    }
    for (int i = 0; i < q; ++i) {
        int code;
        cin >> code;
        if (code == 1) {
            int k, u;
            cin >> k >> u;
            update(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << sum(b) - sum(a - 1) << endl;
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
