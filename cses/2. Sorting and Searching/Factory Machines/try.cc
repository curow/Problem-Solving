#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10;
int a[N];
int n, t;
int search(int l, int r) {
    while (l < r) {
        int m = (l + r) / 2;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            k += m / a[i];
        }
        if (k >= t) r = m;
        else l = m + 1;
    }
    return l;
}

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << search(1, t * a[0]) << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
