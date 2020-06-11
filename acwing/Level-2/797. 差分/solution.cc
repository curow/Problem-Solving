#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        d[i] += x;
        if (i + 1 <= n) d[i + 1] -= x;
    }
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        d[l] += c;
        if (r + 1 <= n) d[r + 1] -= c;
    }
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        s += d[i];
        cout << s << ' ';
    }
    cout << endl;
    return 0;
}
