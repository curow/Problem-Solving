#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

void quick_sort(vector<int> &q, int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1;
    int x = q[l + rand() % (r - l)];
    while (i < j) {
        do ++i; while (q[i] < x);
        do --j; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> q(n);
    for (auto &x : q) cin >> x;
    quick_sort(q, 0, n - 1);
    for (const auto &x : q) cout << x << " ";
    cout << endl;
    return 0;
}
