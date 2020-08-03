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
    for (int k = 1; k <= n; ++k) {
        long long cnt = 0;
        auto valid_count = [&](int i, int j) -> int {
            int remain = k * k - 1;
            for (auto o: offsets) {
                int x = i + o.first, y = j + o.second;
                if (x >= 1 && x <= k && y >= 1 && y <= k)
                    --remain;
            }
            return remain;
        };
        for (int i = 1; i <= k; ++i) {
            cnt += valid_count(i, i);
        }
        for (nt i = 1; i <= k; ++i) {
            for (int j = i + 1; j <= k; ++j) {
                cnt += 2 * valid_count(i, j);
            }
        }
        cout << cnt / 2 << endl;
    }
    return 0;
}i
