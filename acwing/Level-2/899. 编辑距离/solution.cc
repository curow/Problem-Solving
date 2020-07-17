#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int distance(string a, string b) {
    int n = a.size(), m = b.size();
    a = " " + a;
    b = " " + b;

    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) f[i][0] = i;
    for (int j = 0; j <= m; ++j) f[0][j] = j;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
            if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
        }
    }

    return f[n][m];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &x : s) {
        cin >> x;
    }

    for (int i = 0; i < m; ++i) {
        string x;
        int k;
        cin >> x >> k;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (distance(s[j], x) <= k) ++cnt;
        }
        cout << cnt << endl;
    }

    return 0;
}
