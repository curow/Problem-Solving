#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct S{
    int s, t;
    bool operator < (const S& s2) {
        return s < s2.s;
    }
} se[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> se[i].s >> se.t;
    }
    sort(se, se + n);
    int seat = 1;
    for (int i = 0; i < n; i ++) {
        int j = i + 1;
        if (j >= n) break;
        int cnt = 1;
        while (j < n && se[j].s < se[i].t) {
            j ++;
            cnt ++;
        }
        seat = max(seat, cnt);
    }
    cout << seat << endl;

}

int main() {

#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
    // ios_base::sync_with_stdio(0);
    // cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);  // redirects standard input
    /* freopen("output.txt", "w", stdout); // redirects standard output */
#endif
    // solve the problem
    solve();
#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
