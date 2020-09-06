#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10;
int n, x, a[N];

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int last_negative = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < 0) last_negative = i;
        a[i] += a[i - 1];
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int v = x + a[i - 1];
        int low, up;
        if (last_negative >= i) {
            low = lower_bound(a + i, a + last_negative + 1, v, greater<int>()) - a;
            if (low < last_negative + 1 && a[low] == v) {
                up = upper_bound(a + i, a + last_negative + 1, v, greater<int>()) - a;
                cnt += up - low;
            }
            low = lower_bound(a + last_negative + 1, a + n + 1, v) - a;
            if (low < n + 1 && a[low] == v) {
                up = upper_bound(a + last_negative + 1, a + n + 1, v) - a;
                cnt += up - low;
            }
        } else {
            low = lower_bound(a + i, a + n + 1, v) - a;
            if (low < n + 1 && a[low] == v) {
                up = upper_bound(a + last_negative + 1, a + n + 1, v) - a;
                cnt += up - low;
            }
        }
    }
    cout << cnt << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
