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
    int i = 0, res = 1;
    count[a[i]] = 1;
    for (int j = 1; j < n; ++j) {
        while (count[a[j]] > 0) {
            --count[a[i]];
            ++i;
        }
        ++count[a[j]];
        res = max(res, j - i + 1);
    }
    cout << res << endl;
    return 0;
}
