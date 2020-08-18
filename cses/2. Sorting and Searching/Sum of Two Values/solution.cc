#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    bool find = false;
    while (i < j) {
        int s = a[i].first + a[j].first;
        if (s > x) {
            --j;
        } else if (s < x) {
            ++i;
        } else {
            find = true;
            cout << a[i].second << " " << a[j].second << endl;
            break;
        }
    }
    if (!find) cout << "IMPOSSIBLE" << endl;
    return 0;
}
