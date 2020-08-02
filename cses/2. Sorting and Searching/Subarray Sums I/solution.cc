#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int s = 0, cnt = 0;
    for (int l = 0, r = -1; l < n; ++l) {
        while (r + 1 < n && s + nums[r + 1] <= x) s += nums[++r];
        if (s == x) ++cnt;
        if (r >= l) s -= nums[l];
        else r = l;
    }
    cout << cnt << endl;
    return 0;
}
