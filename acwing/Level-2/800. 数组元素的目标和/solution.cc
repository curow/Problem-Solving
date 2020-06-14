#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n, 0), b(m, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    for (int i = 0, j = m - 1; i < n && j >= 0;) {
        int z = a[i] + b[j];
        if (z > x) --j;
        else if (z < x) ++i;
        else {
            cout << i << ' ' << j << endl;
            return 0;
        }
    }
    return 0;
}
