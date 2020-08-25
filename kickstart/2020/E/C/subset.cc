#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int n = 5;
vector<int> subset;
void search(int k) {
    if (k == n) {
        for (auto x : subset) cout << x << " ";
        cout << endl;
    } else {
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
        search(k + 1);
    }
}

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    // solve the problem
    search(0);

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
