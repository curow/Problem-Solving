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
        int n, m, k;
		cin >> n, m, k;
        vector<int> v(k);
        for (auto &x : v) cin >> x;

		cout << "Case #" << t << ": " << endl;
	}

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
