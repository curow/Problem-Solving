#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < m; ++j) cin >> b[j];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, count = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= k) {
            ++i;
            ++j;
            ++count;
        } else if (a[i] > b[j] + k) {
            ++j;
        } else {
            ++i;
        }
    }
    cout << count << endl;
    return 0;
}
