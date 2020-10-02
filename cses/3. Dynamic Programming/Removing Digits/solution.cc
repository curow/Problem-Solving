#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, INF = 1e9;
int value[N];
bool ready[N];

int solve(int x) {
    if (x == 0) return 0;
    if (ready[x]) return value[x];
    int z = x, best = INF;
    while (z > 0) {
        int d = z % 10;
        z = z / 10;
        if (d > 0) best = min(best, 1 + solve(x - d));
    }
    ready[x] = true;
    value[x] = best;
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
