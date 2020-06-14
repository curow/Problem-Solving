#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int res = 0;
    unordered_map<int, int> loc;
    for (int i = 0, j = 0; j < n; ++j) {
        if (loc.count(a[j]) && loc[a[j]] >= i) {
            i = loc[a[j]] + 1;
        }
        loc[a[j]] = j;
        res = max(res, j - i + 1);
    }
    cout << res << endl;
    return 0;
}
