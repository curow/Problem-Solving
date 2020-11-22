/*
ID: zhiwenx2
TASK: test
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
    int a, b;
    cin >> a >> b;
    cout << a+b << endl;
}

int main() {
#ifndef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
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
