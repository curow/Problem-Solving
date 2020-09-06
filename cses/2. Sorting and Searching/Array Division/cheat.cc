#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10;
int n, k, a[N];

bool check(int x) {
    int cnt = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > x) return false;
        if (s + a[i] <= x) {
            s += a[i];
        } else {
            cnt += 1;
            s = a[i];
        }
    }
    cnt += 1;
    return cnt <= k;
}

int search(int l, int r) {
    while (l < r) {
        int m = (l + r) >> 1;
        if (check(m)) r = m;
        else l = m + 1;
    }
    return l;
}

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    cin >> n >> k;
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    cout << search(0, s) << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
