#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> offsets;
    for (int i : {-1, 1}) {
        for (int j : {-2, 2}) {
            offsets.push_back({i, j});
            offsets.push_back({j, i});
        }
    }
    int basic[5] = {0, 0, 6, 28, 96};
    for (int k = 1; k <= 4 && k <= n; ++k) cout << basic[k] << endl;
    for (int k = 5; k <= n; ++k) {
        long long cnt = (long long) pow(k - 4, 2) * (k * k - 1 - 8);
        auto valid_count = [&](int i, int j) -> int {
            int remain = k * k - 1;
            for (auto o: offsets) {
                int x = i + o.first, y = j + o.second;
                if (x >= 1 && x <= k && y >= 1 && y <= k)
                    --remain;
           }
            return remain;
        };
        for (int j = 1; j <= k - 1; ++j) cnt += 4 * valid_count(1, j);
        for (int j = 2; j <= k - 2; ++j) cnt += 4 * valid_count(2, j);
        cout << cnt / 2 << endl;
    }
    return 0;
}
