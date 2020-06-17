#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> PII;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    vector<PII> add(n);
    for (int i = 0; i < n; ++i) {
        int x, c;
        cin >> x >> c;
        nums[i] = x;
        add[i] = {x, c};
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    /* for (int x : nums) cout << x << ' '; */
    /* cout << endl; */

    auto find = [&](int target) {
        int l = 0, r = size(nums) - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    };

    vector<int> val(size(nums), 0);
    for (auto const [x, c] : add) {
        int idx = find(x);
        val[idx] += c;
    }
    
    /* for (int x : val) cout << x << " "; */
    /* cout << endl; */

    for (int i = 1; i < size(val); ++i) val[i] += val[i - 1];

    /* for (int x : val) cout << x << " "; */
    /* cout << endl; */

    while (m--) {
        int l, r;
        cin >> l >> r;
        int left = find(l), right = find(r);
        if (nums[left] > l) ++left;
        /* cout << l << " " << r << endl; */
        /* cout << left << " " << right << endl; */
        if (left > right) {
            cout << 0 << endl;
            continue;
        }
        if (left == 0) cout << val[right] << endl;
        else cout << val[right] - val[left - 1] << endl;
    }
    return 0;
}

