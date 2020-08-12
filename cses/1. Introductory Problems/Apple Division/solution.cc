#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll s = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        s += a[i];
    }
    vector<ll> subset;
    ll best = 1e18;
    function<void(ll)> search;
    search = [&](ll k) -> void {
        if (k == n) {
            ll a = accumulate(subset.begin(), subset.end(), 0LL), b = s - a;
            best = min(best, abs(a - b));
            return;
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
