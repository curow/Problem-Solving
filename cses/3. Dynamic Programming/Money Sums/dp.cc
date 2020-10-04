#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    #ifdef DEBUG
    freopen("input.txt", "r", stdin); // redirects standard input
    freopen("output.txt", "w", stdout); // redirects standard output
    #endif

    // solve the problem
    int n;
    cin >> n;
    int a[n + 1], sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    bool dp[n + 1][sum + 1];
    dp[0][0] = true;
    for (int j = 1; j <= sum; ++j) dp[0][j] = false;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (!dp[i][j]) {
                int k = j - a[i];
                if (k >= 0) dp[i][j] = dp[i - 1][k];
            }
        }
    }
    vector<int> s;
    s.reserve(sum + 1);
    for (int i = 1; i <= sum; ++i) {
        if (dp[n][i]) s.push_back(i);
    }
    cout << s.size() << endl;
    for (const int x : s) cout << x << " ";
    cout << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
