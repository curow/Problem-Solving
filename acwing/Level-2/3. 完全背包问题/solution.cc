#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= c; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
        }
    }

    cout << dp[n][c] << endl;
    return 0;
}
