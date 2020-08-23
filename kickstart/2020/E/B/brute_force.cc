#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

int n, a, b, c;
vector<int> buildings(110);
bool search(int k) {
    if (k == n) {
        int a_hat = 1;
        int mx = buildings[0];
        for (int i = 1; i < n; ++i) {
            if (buildings[i] >= mx) {
                ++a_hat;
                mx = buildings[i];
            }
        }
        int b_hat = 1;
        mx = buildings[n - 1];
        for (int j = n - 2; j >= 0; --j) {
            if (buildings[j] >= mx) {
                ++b_hat;
                mx = buildings[j];
            }
        }
        int c_hat = 0;
        for (int k = 0; k < n; ++k) {
            if (buildings[k] == mx) {
                ++c_hat;
            }
        }
        if (a == a_hat && b == b_hat && c == c_hat) {
            for (int i = 0; i < n; ++i) {
                if (i == n - 1) cout << buildings[i] << endl;
                else cout << buildings[i] << " ";
            }
            return true;
        } else {
            return false;
        }
    }
    for (int i = 1; i <= n; ++i) {
        buildings[k] = i;
        if (search(k + 1)) {
            return true;
        }
    }
    return false;
}

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    // solve the problem
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n >> a >> b >> c;
		cout << "Case #" << t << ": ";
        if (search(0)) {
            continue;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
	}

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
