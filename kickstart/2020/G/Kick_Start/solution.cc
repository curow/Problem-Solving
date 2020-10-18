#include <bits/stdc++.h>
using namespace std;

string s;
string kick = "KICK", start = "START";
bool begin_with(size_t i, string substring) {
    if (s.size() - i < substring.size()) return false;
    for (char c : substring) {
        if (s[i++] != c) return false;
    }
    return true;
}

void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> s;
        int num_kick = 0, num_start = 0;
        int cnt = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (begin_with(i, kick)) {
                ++num_kick;
            } else if (begin_with(i, start)) {
                ++num_start;
                cnt += num_kick;
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
