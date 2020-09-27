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
        int n, k;
		cin >> n >> k;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            int s, e;
            cin >> s >> e;
            v.push_back({s, e});
        }
        sort(v.begin(), v.end());
        int cnt = 0, last = 0;
        for (const auto &p : v) {
            int s, e;
            tie(s, e) = p;
            if (last >= e) {
                continue;
            } else {
                s = max(s, last);
                int remain = e - s;
                if (remain % k == 0) {
                    cnt += remain / k;
                    last = e;
                } else {
                    cnt += remain / k + 1;
                    last = e + (k - remain % k);
                }
            }
        }
		cout << "Case #" << t << ": " << cnt << endl;
	}

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
