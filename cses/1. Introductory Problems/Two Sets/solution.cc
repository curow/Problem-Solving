#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long s = n * (n + 1) / 2;
    if (s % 2) cout << "NO" << endl;
    else {
        vector<int> first;
        s /= 2;
        while (n && s >= n) {
            first.push_back(n);
            s -= n;
            --n;
        }
        if (s > 0) first.push_back(s);
        vector<int> second;
        for (int i = 1; i <= n; ++i) {
            if (i != s) {
                second.push_back(i);
            }
        }
        cout << "YES" << endl;
        cout << first.size() << endl;
        for (auto it = first.rbegin(); it != first.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
        cout << second.size() << endl;
        for (auto x : second) cout << x << " ";
        cout << endl;
    }
    return 0;
}
