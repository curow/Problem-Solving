#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> prices;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        prices.insert(x);
    }
    for (int i = 0; i < m; ++i) {
        int tol;
        cin >> tol;
        auto it = prices.lower_bound(tol);
        if (it != prices.end()) {
            cout << *it << endl;
            prices.erase(it);
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
