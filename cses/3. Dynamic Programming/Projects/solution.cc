#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n;
struct Project {
    int start, end, reward;
    bool operator< (const Project &rhs) {
        return end < rhs.end;
    }
} projects[N];

long long dp[2 * N];

void solve() {
    cin >> n;
    map<int, int> compression;
    for (int i = 0; i < n; ++i) {
        Project& x = projects[i];
        cin >> x.start >> x.end >> x.reward;
        compression[x.start], compression[x.end];
    }
    int index = 0;
    for (auto &[_, value] : compression) {
        value = ++index;
    }
    for (int i = 0; i < n; ++i) {
        Project& x = projects[i];
        x.start = compression[x.start];
        x.end = compression[x.end];
    }
    sort(projects, projects + n);
    dp[0] = 0;
    for (int i = 1; i <= index; ++i) {
        dp[i] = dp[i - 1];
        int l, r;
        l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (projects[mid].end >= i) r = mid;
            else l = mid + 1;
        }
        for (int k = l; k < n && projects[k].end == i; ++k) {
            dp[i] = max(dp[i], dp[projects[k].start - 1] + projects[k].reward);
        }
    }
    cout << dp[index] << endl;
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
