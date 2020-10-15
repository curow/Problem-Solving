#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, bool>> pass(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> pass[2 * i].first;
        pass[2 * i].second = true;
        cin >> pass[2 * i + 1].first;
        pass[2 * i + 1].second = false;
    }
    sort(pass.begin(), pass.end());
    int max_pass = 1;
    int i = 1;
    int cnt = 1;
    int last = pass[0].first;
    while (i < 2 * n) {
        while (i < 2 * n && pass[i].first == last) {
            if (pass[i].second) ++cnt;
            else --cnt;
            ++i;
        }
        max_pass = max(cnt, max_pass);
        if (i == 2 * n) break;
        else last = pass[i].first;
    }
    cout << max_pass << endl;
}

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
    solve();
#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
