/* #include <bits/stdc++.h> */
#include <iostream>
#include <cmath>
using namespace std;

inline bool is_odd(int a) {
    return a % 2;
}

long long same_width_max_number(long long x) {
    long long ans = 0;
    while (x > 0) {
        ans *= 10;
        ans += 9;
        x /= 10;
    }
    return ans;
}

int width(long long x) {
    int cnt = 0;
    while (x > 0) {
        cnt += 1;
        x /= 10;
    }
    return cnt;
}

int count_odd(int a, int b) {
    int cnt = 0;
    for (int i = a; i <= b; ++i) cnt += is_odd(i);
    return cnt;
}

int count_even(int a, int b) {
    return b - a + 1 - count_odd(a, b);
}

int digit(long long x, int loc, int len) {
    return (x / (long long)pow(10, len - loc)) % 10;
}

long long count_boring(long long a, long long b, int len, bool odd_first) {
    if (a > b) return 0;
    if (len == 1) {
        if (odd_first) return count_odd(a, b);
        else return count_even(a, b);
    }
    int da = digit(a, 1, len), db = digit(b, 1, len);
    if (da == db) {
        if ((odd_first && is_odd(da)) || (!odd_first && !is_odd(da))) {
            return count_boring(a % (long long)pow(10, len - 1),
                                b % (long long)pow(10, len - 1),
                                len - 1, !odd_first);
        }
    }
    long long cnt = 0;
    int repeat = 0;
    for (int i = da; i <= db; ++i) {
        if ((odd_first && is_odd(i)) || (!odd_first && !is_odd(i))) {
            if (i == da) {
                cnt += count_boring(a % (long long)pow(10, len - 1),
                                    (long long)pow(10, len - 1) - 1,
                                    len - 1, !odd_first);
            } else if (i < db) {
                ++repeat;
            } else {
                cnt += count_boring(0,
                                    b % (long long)pow(10, len - 1),
                                    len - 1, !odd_first);

            }
        }
    }
    cnt += repeat * count_boring(0,
                                 (long long)pow(10, len - 1) - 1,
                                 len - 1, !odd_first);
    return cnt;
}

void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long l, r;
        cin >> l >> r;
        long long total_cnt = 0;
        long long a = l, b = min(same_width_max_number(a), r);
        while (a <= b && b <= r) {
            total_cnt += count_boring(a, b, width(a), true);
            a = b + 1;
            b = min(same_width_max_number(a), r);
        }
        cout << "Case #" << t << ": " << total_cnt << endl;
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
