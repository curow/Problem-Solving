#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e7;
struct pair_hash {
    size_t operator () (const pair<int, int> &p) const {
        int x = ((p.second - p.first + 1) >> 16) + p.second;
        return hash<int>{}(x);
    }
};
unordered_map<pair<int, int>, int, pair_hash> f(N);

int main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
 
    // solve the problem
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        f[{i, i}] = x;
    }
    for (int k = 2; k <= n; k *= 2) {
        for (int i = 1; i + k - 1 <= n; ++i) {
            int j = i + k - 1;
            f[{i, j}] = min(f[{i, i + k / 2 - 1}], f[{i + k / 2, j}]);
        }
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        int w = (int) pow(2, (int) log2(b - a + 1));
        printf("%d\n", min(f[{a, a + w - 1}], f[{b - w + 1, b}]));
    }
 
    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
