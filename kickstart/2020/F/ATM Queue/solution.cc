#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    #ifdef DEBUG
    freopen("input.txt", "r", stdin); // redirects standard input
    freopen("output.txt", "w", stdout); // redirects standard output
    #endif

    // solve the problem
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
        int n, x;
		cin >> n >> x;
        vector<pair<int, int>> v;
        for (int i = 1; i <= n; ++i) {
            int c;
            cin >> c;
            v.push_back({i, c});
        }
        auto comp = [&](const pair<int, int> &a, const pair<int, int> &b) {
            int xa = a.second / x, xb = b.second / x;
            xa += a.second % x > 0 ? 1 : 0;
            xb += b.second % x > 0 ? 1 : 0;
            if (xa < xb) {
                return true;
            } else if (xa > xb) {
                return false;
            } else {
                return a.first < b.first;
            }
        };
        sort(v.begin(), v.end(), comp);
		cout << "Case #" << t << ": ";
        for (const auto p : v) {
            cout << p.first << " ";
        }
        cout << endl;
	}

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
