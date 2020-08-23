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
        int n;
		cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        int i = 0, j = 2, best = 2;
        while (j < n) {
            if (a[j] - a[j - 1] == a[j - 1] - a[j - 2]) ++j;
            else i = j - 1, j = i + 2;
            best = max(best, j - i);
        }
		cout << "Case #" << t << ": " << best << endl;
	}

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
