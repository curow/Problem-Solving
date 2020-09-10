#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10;
int a[N];

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    #ifdef DEBUG
    freopen("input.txt", "r", stdin); // redirects standard input
    freopen("output.txt", "w", stdout); // redirects standard output
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            cout << 0 << " ";
        }
        return 0;
    }
    multiset<int> left, right;
    for (int i = 0; i < k / 2; ++i) {
        right.insert(a[i]);
    }
    auto balance = [&](int x) -> void {
        auto it = right.begin();
        if (x > *it) {
            left.insert(*it);
            right.erase(it);
            right.insert(x);
        } else {
            left.insert(x);
        }
    };
    for (int i = k / 2; i < k; ++i) {
        balance(a[i]);
    }
    int median = *left.rbegin(), s = 0;
    for (int i = 0; i < k; ++i) {
        s += abs(a[i] - median);
    }
    cout << s << " ";
    for (int i = k; i < n; ++i) {
        if (a[i - k] <= *left.rbegin()) {
            left.erase(left.find(a[i - k]));
        } else {
            right.erase(right.find(a[i - k]));
            right.insert(*left.rbegin());
            left.erase(prev(left.end()));
        }
        balance(a[i]);
        int prev_median = median;
        median = *left.rbegin();
        s += abs(median - a[i]) - abs(prev_median - a[i - k])
             + ((k + 1) / 2 - 1 - k / 2) * (median - prev_median);
        cout << s << " ";
    }

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
