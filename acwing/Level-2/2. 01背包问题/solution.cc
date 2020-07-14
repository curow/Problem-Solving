#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> val(n + 1), weight(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> weight[i] >> val[i];

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (j >= weight[i]) {
                dp[i][j] = max(dp[i - 1][j - weight[i]] + val[i], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][w] << endl;
}
