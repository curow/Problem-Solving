#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10;
int a[N];

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    int n, k;
    cin >> n >> k;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        t += a[i];
    }
    double mean = (double) t / k;
    int s = a[0], ms = s;
    cout << a[0] << " ";
    int i = 1;
    while (k > 1 && i < n) {
        if (abs(s + a[i] - mean) <= abs(s - mean)) {
            s += a[i];
            cout << a[i] << " ";
        } else {
            ms = max(ms, s);
            cout << endl;
            s = a[i];
            cout << a[i] << " ";
            --k;
        }
        ++i;
    }
    for (int j = i; j < n; ++j) {
        s += a[j];
        cout << a[j] << " ";
    }
    cout << endl;
    ms = max(ms, s);
    cout << ms << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
