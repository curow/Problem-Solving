#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

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
    int n, a, b;
    cin >> n >> a >> b;
    ll prefix_sum[n + 1];
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> prefix_sum[i];
        prefix_sum[i] += prefix_sum[i - 1];
    }
    ll best = -INF;
    deque<pair<int, ll>> sliding_minimum;
    for (int i = a; i <= n; ++i) {
        // pop value that is out of range
        if (i - b - 1 >= 0 && !sliding_minimum.empty() && sliding_minimum.front().first == i - b - 1) {
            sliding_minimum.pop_front();
        }
        // pop values that won't be used
        while(!sliding_minimum.empty() && sliding_minimum.back().second >= prefix_sum[i - a]) {
            sliding_minimum.pop_back();
        }
        sliding_minimum.push_back({i - a, prefix_sum[i - a]});
        best = max(best, prefix_sum[i] - sliding_minimum.front().second);
    }
    cout << best << endl;

#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
