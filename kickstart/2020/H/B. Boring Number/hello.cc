#include <bits/stdc++.h>
using namespace std;

inline bool isOdd(int a) {
    return a % 2;
}

bool isBoring(long long x) {
    vector<int> digits;
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    const int len = digits.size();
    for (int i = -1; i >= -len; --i) {
        /* cout << digits[len - i] << "is odd? " << isOdd(digits[len - i]) << endl; */
        /* cout << -i << "is odd? " << isOdd(-i) << endl; */
        if ((isOdd(digits[len + i]) && isOdd(-i))
            || (!isOdd(digits[len + i]) && !isOdd(-i))) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long l, r;
        cin >> l >> r;
        long long cnt = 0;
        for (long long i = l; i <= r; ++i) {
            if (isBoring(i)) {
                ++cnt;
                /* cout << i << endl; */
            }
        }
        cout << "Case #" << t << ": " << cnt << endl;
    }
}

int main() {
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);  // redirects standard input
    /* freopen("output.txt", "w", stdout); // redirects standard output */
#endif
    // solve the problem
    solve();
#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
