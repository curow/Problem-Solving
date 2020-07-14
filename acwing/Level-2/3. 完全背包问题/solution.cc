#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    scanf("%d %d", &n, &c);

    vector<int> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &w[i], &v[i]);
    }

    vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= c; ++j) {
            for (int k = 0; k * w[i] <= j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }

    printf("%d\n", dp[n][c]);
    return 0;
}
