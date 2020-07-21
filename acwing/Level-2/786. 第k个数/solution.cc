#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

using namespace std;

int quick_select(vector<int> &q, int l, int r, int k) {
    if (k > r - l + 1) throw invalid_argument("k must not be greater than the size of inteval (r - l + 1)");
    if (l >= r) return q[l];
    int i = l - 1, j = r + 1;
    int x = q[l + rand() % (r - l)];
    while (i < j) {
        do ++i; while (q[i] < x);
        do --j; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    if (j - l + 1 >= k) {
        return quick_select(q, l, j, k);
    } else {
        return quick_select(q, j + 1, r, k - (j - l + 1));
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> q(n);
    for (auto &x : q) cin >> x;
    cout << quick_select(q, 0, n - 1, k) << endl;
    return 0;
}
