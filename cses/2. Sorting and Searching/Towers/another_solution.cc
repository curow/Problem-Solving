#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> top;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        auto it = upper_bound(top.begin(), top.end(), x);
        if (it == top.end()) {
            top.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << top.size() << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
