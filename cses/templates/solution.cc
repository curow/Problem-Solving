#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    cin.sync_with_stdio(false);

    // solve the problem

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
