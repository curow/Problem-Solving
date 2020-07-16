#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            int x;
            cin >> x;
            v[n - i].push_back(x);
        }
    }

    vector<int> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = v[0][i];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            dp[j] = v[i][j] + max(dp[j], dp[j + 1]);
        }
    }

    cout << dp[0] << endl;
    return 0;
}
