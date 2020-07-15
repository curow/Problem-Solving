#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> w(n + 1), v(n + 1);
    vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i]; ++j) {
            int weight, value;
            cin >> weight >> value;
            w[i].push_back(weight);
            v[i].push_back(value);
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= c; ++j) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k < s[i]; ++k) {
                if (j >= w[i][k]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i][k]] + v[i][k]);
                }
            }
        }
    }

    cout << dp[n][c] << endl;
    return 0;
}
