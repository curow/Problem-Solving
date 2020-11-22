/*
ID: zhiwenx2
TASK: gift1
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
    ll n;
    cin >> n;
    vector<string> names;
    names.reserve(n);
    for (ll i = 0; i < n; ++i) {
        string name;
        cin >> name;
        names.push_back(name);
    }
    map<string, ll> gain, init;
    for (ll i = 0; i < n; ++i) {
        string giver;
        cin >> giver;
        ll money, num;
        cin >> money >> num;
        init[giver] = money;
        if (num == 0) gain[giver] += money;
        else gain[giver] += money % num;
        for (ll j = 0; j < num; ++j) {
            string receiver;
            cin >> receiver;
            gain[receiver] += money / num;
        }
    }
    for (string name : names) {
        cout << name << " " << gain[name] - init[name] << endl;
    }
}

int main() {
#ifndef DEBUG
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
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
