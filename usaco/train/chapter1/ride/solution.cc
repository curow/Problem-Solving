/*
ID: zhiwenx2
TASK: ride
LANG: C++14                 
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

const lld PI = 3.14159265358979323846;
const ll MOD = 1000000007;
const ll INF = 1e18;

void solve() {
    string comet, group;
    cin >> comet >> group;
    auto numbering = [](string s) -> ll {
        ll num = 1;
        for (char x : s) {
            num *= x - 'A' + 1;
            num %= 47;
        }
        return num;
    };
    ll comet_num = numbering(comet), group_num = numbering(group);
    if (comet_num == group_num) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }
}

int main() {
#ifndef DEBUG
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
#endif
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
