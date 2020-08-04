#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> f(n + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                f[i] = (f[i] + f[i - j]) % MOD;
            } else {
                break;
            }
        }
    }
    cout << f[n] << endl;
    return 0;
}
