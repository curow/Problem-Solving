#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);  // redirects standard input
    /* freopen("output.txt", "w", stdout); // redirects standard output */
#endif

    // solve the problem
    size_t n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto &[e, s] : a) cin >> s >> e;
    sort(a.begin(), a.end());
    multiset<int> end_times;
    int skip = 0;
    for (const auto &[e, s] : a) {
        auto pos = end_times.upper_bound(s);
        if (pos != end_times.begin()) {
            --pos;
            end_times.erase(pos);
            end_times.insert(e);
        } else if (end_times.size() < k) {
            end_times.insert(e);
        } else {
            ++skip;
        }
    }
    cout << n - skip << endl;

#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
