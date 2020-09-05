#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10;
int a[N];

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    set<array<int, 2>> s; // store {end time, array index}
    for (int i = 0; i < n; ++i) {
        s.insert({a[i], i});
    }
    int last = 0, i;
    while (t--) {
        auto it = s.begin();
        last = (*it)[0], i = (*it)[1];
        s.erase(it);
        s.insert({last + a[i], i});
    }
    cout << last << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
