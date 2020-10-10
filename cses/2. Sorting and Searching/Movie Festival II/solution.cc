#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
#ifdef DEBUG
    freopen("input.txt", "r", stdin);    // redirects standard input
    /* freopen("output.txt", "w", stdout);  // redirects standard output */
#endif

    // solve the problem
    int n, k;
    cin >> n >> k;
    if (k >= n) {
        cout << n << endl;
        return 0;
    }
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.first >> x.second;
    sort(a.begin(), a.end(),
         [](const pair<int, int> lhs, const pair<int, int> rhs) {
             if (lhs.second < rhs.second) {
                 return true;
             } else if (lhs.second > rhs.second) {
                 return false;
             } else {
                 return lhs.first < rhs.first;
             }
         });
    int skip = 0;
    vector<int> ends(k, 0);
    for (int i = 0; i < n; ++i) {
        int start = a[i].first;
        if (ends[0] > start) {
            ++skip;
        } else { // find the largest end that is smaller or equal to start
            int l = 0, r = k - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (ends[mid] <= start) l = mid;
                else r = mid - 1;
            }
            ends[l] = a[i].second;
            for (int j = l + 1; j < k && ends[j - 1] > ends[j]; ++j) {
                swap(ends[j - 1], ends[j]);
            }
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
