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
        bool swaped = false;
        if (a > b) {
            swap(a, b);
            swaped = true;
        }
        /* cout << "n = " << n << " a = " << a << " b = " << b << " c = " << c << endl; */
        int minimum = a + b - c;
        vector<int> buildings;
        int success = true;
        if (minimum > n) success = false;
        else if (minimum == n) {
            for (int i = 0; i < a - c; ++i) {
                if (n - 1 <= 0) {
                    success = false;
                }
                buildings.push_back(n - 1);
            }
            for (int i = 0; i < c; ++i) {
                buildings.push_back(n);
            }
            for (int i = 0; i < b - c; ++i) {
                if (n - 1 <= 0) {
                    success = false;
                }
                buildings.push_back(n - 1);
            }
        } else {
            for (int i = 0; i < a - c; ++i) {
                if (n - 1 <= 0) {
                    success = false;
                }
                buildings.push_back(n - 1);
            }
            if (c > 1) {
                buildings.push_back(n);
                for (int i = 0; i < n - minimum; ++i) {
                    if (n <= 1) {
                        success = false;
                    }
                    buildings.push_back(1);
                }
                for (int i = 0; i < c - 1; ++i) {
                    buildings.push_back(n);
                }
                for (int i = 0; i < b - c; ++i) {
                    if (n - 1 <= 0) {
                        success = false;
                    }
                    buildings.push_back(n - 1);
                }
            } else {
                buildings.push_back(n);
                for (int i = 0; i < n - minimum; ++i) {
                    if (n <= 1) {
                        success = false;
                    }
                    buildings.push_back(1);
                }
                if (b == c) {
                    success = false;
                } else {
                    for (int i = 0; i < b - c; ++i) {
                        if (n - 1 <= 1) {
                            success = false;
                        }
                        buildings.push_back(n - 1);
                    }
                }
            }

        }
        if (!success) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
            continue;
        } else {
            cout << "Case #" << t << ": ";
            if (swaped) {
                for (int i = n - 1; i >= 0; --i) {
                    if (i == 0) {
                        cout << buildings[i] << endl;
                    } else {
                        cout << buildings[i] << " ";
                    }
                }
            } else {
                for (int i = 0; i < n; ++i) {
                    if (i == n - 1) {
                        cout << buildings[i] << endl;
                    } else {
                        cout << buildings[i] << " ";
                    }
                }
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
