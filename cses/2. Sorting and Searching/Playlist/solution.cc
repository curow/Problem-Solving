#include <bits/stdc++.h>

using namespace std;

int main() {

    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif

    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    int s = 0, e = 0, best = 1;
    unordered_map<int, int> loc;
    int x;
    cin >> x;
    loc[x] = 0;
    for (int i = 1; i < n; ++i) {
        cin >> x;
        if (loc.count(x) == 0 || loc[x] < s) {
            e = i;
            best = max(best, e - s + 1);
        } else {
            s = loc[x] + 1;
        }
        loc[x] = i;
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
