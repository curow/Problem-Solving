/*
ID: zhiwenx2
TASK: friday
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

bool is_leap_year(ll year) {
    if (year % 100 == 0) {
        return year % 400 == 0;
    } else {
        return year % 4 == 0;
    }
}

ll day_of_month(ll year, ll month) {
    switch (month) {
        case 9:
        case 4:
        case 6:
        case 11:
            return 30;
        case 2:
            if (is_leap_year(year)) return 29;
            else return 28;
        default:
            return 31;
    }
}

void solve() {
    ll n;
    cin >> n;
    ll year = 1900, month = 1, day = 1;
    map<ll, ll> thirteen;
    ll weekday = 1;
    while (year != 1900 + n - 1 || month != 12 || day != 31) {
        if (day == 13) ++thirteen[weekday];
        weekday = weekday % 7 + 1;
        day += 1;
        if (day > day_of_month(year, month)) {
            day = 1;
            month += 1;
            if (month > 12) {
                month = 1;
                year += 1;
            }
        }
    }
    vector<ll> order = {6, 7, 1, 2, 3, 4, 5};
    for (ll x : order) {
        cout << thirteen[x];
        if (x == 5) cout << endl;
        else cout << " ";
    }
}

int main() {
#ifndef DEBUG
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
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
