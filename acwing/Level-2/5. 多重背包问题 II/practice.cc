#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int cnt, c;
    cin >> cnt >> c;
    vector<int> w(1), v(1);
    int n = 0;
    for (int i = 0; i < cnt; ++i) {
        int weight, value, remain;
        cin >> weight >> value >> remain;
        int k = 1;
        while (k <= remain) {
            n += 1;
            w.push_back(weight * k);
            v.push_back(value * k);
            remain -= k;
            k *= 2;
        }
        if (remain > 0) {
            n += 1;
            w.push_back(weight * remain);
            v.push_back(value * remain);
        }
    }

    vector<int> dp(c + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = c; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[c] << endl;
    return 0;
}
