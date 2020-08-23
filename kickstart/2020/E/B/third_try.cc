#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

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
        int n, a, b, c;
		cin >> n >> a >> b >> c;
        /* cout << "n = " << n << " a = " << a << " b = " << b << " c = " << c << endl; */
        int minimum = a + b - c;
        if (minimum > n || (n == 1 && ((a - c > 0) || (b - c > 0))) || (n == 2 && n > minimum)) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        vector<int> buildings;
        for (int i = 0; i < a - c; ++i) {
            buildings.puh_back(n - 1);
        }
        if (minimum == n) {
            for (int i = 0; i < c; ++i) {
                buildings.push_back(n);
            }
        } else {
            buildings.push_back(n);
            for (int i = 0; i < n - minimum; ++i) {
                buildings.push_back(1);
            }
            for (int i = 0; i < c - 1; ++i) {
                buildings.push_back(n);
            }
        }
        if (b > c) {
            for (int i = 0; i < b - c; ++i) {
                buildings.push_back(n - 1);
            }
        } else if (b == c && c == 1 && n > minimum) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
            continue;
        }

		cout << "Case #" << t << ": ";
        for (int i = 0; i < n; ++i) {
            if (i == n - 1) {
                cout << buildings[i] << endl;
            } else {
                cout << buildings[i] << " ";
            }
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
