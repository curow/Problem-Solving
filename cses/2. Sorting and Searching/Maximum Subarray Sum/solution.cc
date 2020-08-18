#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), f(n);
    for (auto &x : a) cin >> x;
    f[0] = a[0];
    ll best = f[0];
    for (int i = 1; i < n; ++i) {
        f[i] = max(a[i], f[i - 1] + a[i]);
        best = max(best, f[i]);
    }
    cout << best << endl;
    return 0;
}
