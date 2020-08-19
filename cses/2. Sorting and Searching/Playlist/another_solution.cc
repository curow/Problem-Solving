#include <bits/stdc++.h>

using namespace std;

#define int long long int

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<int, int> loc;
    int best = 0, i = 0;
    for (int j = 1; j <= n; ++j) {
        int x;
        cin >> x;
        i = max(i, loc[x] + 1);
        best = max(best, j - i + 1);
        loc[x] = j;
    }
    cout << best << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
