#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
bool revenge[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        revenge[i] = x == 1 ? true : false;
    }
    int armor[n];
    for (int i = 0; i < n; ++i) armor[i] = 1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += armor[i];
        if (revenge[i] && i + 1 < n) armor[i + 1] += 1;
    }
    cout << cnt << endl;
}

int main() {
    solve();
    return 0;
}
