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
    int x, n;
    cin >> x >> n;
    set<int> lights({0, x});
    multiset<int, greater<int>> lens({x});
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        auto hi = lights.upper_bound(p);
        auto lo = prev(hi);
        int c = *hi - *lo, a = p - *lo, b = *hi - p;
        lights.insert(p);
        lens.erase(lens.lower_bound(c));
        lens.insert(a);
        lens.insert(b);
        cout << *lens.begin() << " ";
    }
    cout << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
