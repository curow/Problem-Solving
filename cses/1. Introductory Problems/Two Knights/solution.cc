#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int basic[5] = {0, 0, 6, 28, 96};
    for (int k = 1; k <= 4 && k <= n; ++k) cout << basic[k] << endl;
    for (int k = 5; k <= n; ++k) {
        const long long num_candidates = k * k - 1;
        long long cnt = (long long) pow(k - 4, 2) * (num_candidates - 8);
        cnt += 4 * (num_candidates - 2);
        cnt += 8 * (num_candidates - 3);
        cnt += 4 * (num_candidates - 4);
        cnt += 4 * (k - 4) * (num_candidates - 4);
        cnt += 4 * (k - 4) * (num_candidates - 6);
        cout << cnt / 2 << endl;
    }
    return 0;
}
