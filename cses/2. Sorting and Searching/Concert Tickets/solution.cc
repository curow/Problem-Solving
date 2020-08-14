#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> prices;
    vector<int> tol(m);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        prices.insert(x);
    }
    for (int i = 0; i < m; ++i) {
        int tol;
        cin >> tol;
        auto it = prices.lower_bound(tol);
        if (it == prices.end()) {
            if (!prices.empty()) {
                --it;
                cout << *it << endl;
                prices.erase(it);
            } else {
                cout << -1 << endl;
            }
        } else if (it == prices.begin()){
            if (*it == tol) {
                cout << tol << endl;
                prices.erase(it);
            } else {
                cout << -1 << endl;
            }
        } else {
            if (*it != tol) --it;
            cout << *it << endl;
            prices.erase(it);
        }
    }
    return 0;
}
