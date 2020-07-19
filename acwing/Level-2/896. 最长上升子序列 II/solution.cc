#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> tails;
    auto search = [&](int l, int r, int x) -> int {
        if (l > r) return -1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (tails[mid] < x) l = mid + 1;
            else r = mid;
        }
        if (tails[l] >= x) return l;
        else return -1;
    };
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int pos = search(0, tails.size() - 1, x);
        if (pos == -1) {
            tails.push_back(x);
        } else {
            tails[pos] = x;
        }
    }
    cout << tails.size() << endl;
    return 0;
}
