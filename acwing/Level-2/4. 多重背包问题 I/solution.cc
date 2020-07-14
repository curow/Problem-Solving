#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> w(n + 1), v(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i] >> s[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= c; ++j) {
            for (int k = 0; k <= s[i] && k * w[i] <= j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }
    
    cout << dp[n][c] << endl;
    return 0;
}
