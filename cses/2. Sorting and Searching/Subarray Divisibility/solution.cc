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
    int n;
    cin >> n;
    map<int, int> s;
    s[0] = 1;
    int cnt = 0, prev = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        prev = x = (x + prev) % n;
        if (x == 0) cnt += s[0];
        else cnt += s[x - n] + s[x] + s[x + n];
        s[x] += 1;
    }
    cout << cnt << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
