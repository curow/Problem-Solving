#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int median = a[n / 2];
    long long cost = 0;
    for (auto &x : a) {
        cost += abs(x - median);
    }
    cout << cost << endl;
    return 0;
}
