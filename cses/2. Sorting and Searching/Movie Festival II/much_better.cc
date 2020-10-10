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
    for (auto &[s, e] : a) cin >> s >> e;
    sort(a.begin(), a.end());
    multiset<int> end_times;
    int ans = 0;
    for (const auto &[s, e] : a) {
        while (!end_times.empty() && *end_times.begin() <= s) {
            end_times.erase(end_times.begin());
        }
        if (end_times.size() < k) {
            ++ans;
            end_times.insert(e);
        } else if (*end_times.rbegin() > e) {
            end_times.erase(--end_times.end());
            end_times.insert(e);
        }
    }
    cout << ans << endl;

#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
