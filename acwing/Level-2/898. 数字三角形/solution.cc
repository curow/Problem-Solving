#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    vector<int> f(n, 0);
    f[0] = v[0][0];
    for (int i = 1; i < n; ++i) {
        for (int j = i; j >= 0; --j) {
            if (j == i) {
                f[j] = v[i][j] + f[j - 1];
            } else if (j == 0) {
                f[j] = v[i][j] + f[j];
            } else {
                f[j] = v[i][j] + max(f[j], f[j - 1]);
            }
        }
    }

    cout << *max_element(f.begin(), f.end()) << endl;
    return 0;
}
