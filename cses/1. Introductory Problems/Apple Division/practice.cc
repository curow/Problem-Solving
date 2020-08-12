#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    ll best = 1e18;
    vector<ll> subset;
    function<void(int)> search;
    search = [&](int k) {
        if (k == n) {
            ll a = accumulate(subset.begin(), subset.end(), 0LL), b = s - a;
            best = min(best, abs(a - b));
        } else {
            subset.push_back(a[k]);
            search(k + 1);
            subset.pop_back();
            search(k + 1);
        }
    };
    search(0);
    cout << best << endl;
    return 0;
}
