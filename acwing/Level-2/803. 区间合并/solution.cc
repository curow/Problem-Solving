#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> PII;

int main() {
    int n;
    cin >> n;
    vector<PII> pairs;
    while (n--) {
        int l, r;
        cin >> l >> r;
        pairs.push_back({l, r});
    }
    sort(pairs.begin(), pairs.end());

    int cnt = 0, front = INT_MIN;
    for (auto &[l, r] : pairs) {
        if (front < l) {
            ++cnt;
            front = r;
        } else {
            front = max(front, r);
        }
    }
    cout << cnt << endl;

    return 0;
}
