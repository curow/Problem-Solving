#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ll n;
    cin >> n;
    ll remain = n * (n + 1) / 2;
    while (--n) {
        int x;
        cin >> x;
        remain -= x;
    }
    cout << remain << endl;
    return 0;
}
