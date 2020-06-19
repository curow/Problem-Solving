#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> PII;

int main() {
    int n, m;
    cin >> n >> m;
    vector<PII> adds(n), query(m);
    vector<int> all;

    for (int i = 0; i < n; ++i) {
        int x, c;
        cin >> x >> c;
        adds[i] = {x, c};
        all.push_back(x);
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        query[i] = {l, r};
        all.push_back(l);
        all.push_back(r);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    auto find = [&](int x) {
        int l = 0, r = size(all) - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (all[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return l + 1;
    };
    
    vector<int> val(size(all) + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x, c;
        x = adds[i].first;
        c = adds[i].second;
        int idx = find(x);
        val[idx] += c;
    }

    for (int i = 1; i < size(val); ++i) val[i] += val[i - 1];

    for (int i = 0; i < m; ++i) {
        int l, r;
        l = query[i].first;
        r = query[i].second;
        int kl = find(l);
        int kr = find(r);
        cout << val[kr] - val[kl - 1] << endl;
    }

    return 0;
}
