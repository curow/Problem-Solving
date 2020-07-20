#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    vector<vector<int>> f(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; ++i) {
        f[i][i] = 0;
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1; i + k - 1 <= n; ++i) {
            int j = i + k - 1;
            for (int x = i; x + 1 <= j; ++x) {
                f[i][j] = min(f[i][j], f[i][x] + f[x + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}
