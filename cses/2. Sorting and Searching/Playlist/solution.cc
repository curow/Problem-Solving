#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int val[N];

int main() {

    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", val + i);
    int s = 0, e = 0, best = 1;
    unordered_map<int, int> loc;
    loc[val[0]] = 0;
    for (int i = 1; i < n; ++i) {
        int x = val[i];
        if (loc.count(x) == 0 || loc[x] < s) {
            e = i;
            best = max(best, e - s + 1);
        } else {
            s = loc[x] + 1;
        }
        loc[x] = i;
    }
    printf("%d\n", best);

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif

    return 0;
}
