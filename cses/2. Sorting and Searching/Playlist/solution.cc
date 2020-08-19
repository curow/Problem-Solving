#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int val[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> val[i];
    int s = 0, e = 0, best = 1;
    unordered_map<int, int> loc;
    loc[val[0]] = 0;
    for (int i = 1; i < n; ++i) {
        int x = val[i];
        if (loc.count(x) == 0 || loc[x] < s) {
            e = i;
            best = max(best, e - s + 1);
        } else {
            s = loc[x] + 1;
        }
        loc[x] = i;
    }
    cout << best << endl;
    return 0;
}
