#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int count = 0, best = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (a[i] < b[j]) {
            ++count;
            ++i;
        } else if (a[i] > b[j]) {
            --count;
            ++j;
        } else {
            ++i;
            ++j;
        }
        best = max(best, count);
    }
    cout << best << endl;
    return 0;
}
