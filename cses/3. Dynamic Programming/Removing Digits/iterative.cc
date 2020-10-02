#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, INF = 1e9;
int value[N];

int solve(int x) {
    value[0] = 0;
    for (int i = 1; i <= x; ++i) {
        value[i] = INF;
        int j = i;
        while (j > 0) {
            int d = j % 10;
            j /= 10;
            if (d > 0) value[i] = min(value[i], 1 + value[i - d]);
        }
    }
    return value[x];
}

int main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    #ifdef DEBUG
    freopen("input.txt", "r", stdin); // redirects standard input
    freopen("output.txt", "w", stdout); // redirects standard output
    #endif

    // solve the problem
    int x;
    cin >> x;
    cout << solve(x) << endl;
    

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
