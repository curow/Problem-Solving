#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // from the description, number of object classes is at most 1000,
    // and the number of each class is at most 2000
    // so we know if we use binary optimization, the total number of object
    // is at most ceil(1000 * log(2001))
    /* const int N = ceil(1000 * (log(2001) + 1)); */

    int count, c;
    cin >> count >> c;
    vector<int> w(1), v(1);
    int n = 0;
    for (int i = 0; i < count; ++i) {
        int weight, value, remain;
        cin >> weight >> value >> remain;
        int k = 1;
        while (k <= remain) {
            n += 1;
            w.push_back(k * weight);
            v.push_back(k * value);
            remain -= k;
            k *= 2;
        }
        if (remain > 0) {
            n += 1;
            w.push_back(remain * weight);
            v.push_back(remain * value);
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
