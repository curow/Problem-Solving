#include <bits/stdc++.h>

#define int __int64_t

using namespace std;

const int N = 2e5 + 10;
const int INF = 1e9 + 10;
int top[N];

int binary_search(int lo, int hi, int val) {
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (top[mid] > val) hi = mid;
        else lo = mid + 1;
    }
    if (top[lo] > val) return lo;
    else return lo + 1;
}

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int m = 0;
    top[0] = INF;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int k = binary_search(0, m, x);
        top[k] = x;
        m = max(m, k);
    }
    cout << m + 1 << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
