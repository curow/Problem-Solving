#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    unordered_map<int, int> count;
    int res = 0;
    for (int i = 0, j = 0; j < n; ++j) {
        ++count[a[j]];
        while (i < j && count[a[j]] > 1) {
            --count[a[i]];
            ++i;
        }
        res = max(res, j - i + 1);
    }
    cout << res << endl;
    return 0;
}
