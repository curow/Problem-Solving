#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10;
array<int, 2> a[N]; // store [duration, deadline]

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1];
    sort(a, a + n);
    int t = 0, reward = 0;
    for (int i = 0; i < n; ++i) {
        t += a[i][0];
        reward += a[i][1] - t;
    }
    cout << reward << endl;
    
    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
