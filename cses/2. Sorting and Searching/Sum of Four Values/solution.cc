#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    int n, x;
    cin >> n >> x;
    array<int, 2> a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a, a + n);
    for (int i = 0; i + 3 < n; ++i) {
        if (a[i][0] + 3 > x) break;
        for (int j = i + 1; j + 2 < n; ++j) {
            if (a[i][0] + a[j][0] + 2 > x) break;
            int s = x - a[i][0] - a[j][0];
            int l = j + 1, r = n - 1;
            while (l < r) {
                int k = a[l][0] + a[r][0];
                if (k < s) {
                    ++l;
                } else if (k > s) {
                    --r;
                } else {
                    cout << a[i][1] + 1 << " " << a[j][1] + 1 << " " << a[l][1] + 1 << " " << a[r][1] + 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
