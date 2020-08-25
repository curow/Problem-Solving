#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 1e5 + 10, INF = 1e18;
int n;
int best_time, best_remain;
int e[N], r[N], v[N];
vector<int> subset;
bool search(int k) {
    if (k == n) {
        if (subset.empty()) return false;
        int m = subset.size();
        for (int i = 0; i < m; ++i) {
            v[subset[i]] = -INF;
        }
        int time = 0, i = 0;
        while (i < 2 * m && time - v[subset[i % m]] >= r[subset[i % m]]) {
            time += e[subset[i % m]];
            v[subset[i % m]] = time;
            i += 1;
        }
        if (i == 2 * n) {
            best_time = INF;
            best_remain = n;
            return true;
        } else if (i == 2 * m) {
            best_time = INF;
            best_remain = max(best_remain, m);
            return false;
        } else {
            if (time > best_time) {
                best_time = time;
                best_remain = m;
            } else if (time == best_time) {
                best_remain = max(best_remain, m);
            }
            return false;
        }
    } else {
        subset.push_back(k);
        bool ok = search(k + 1);
        subset.pop_back();
        if (!ok) return search(k + 1);
        else return true;
    }
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
		cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> e[i] >> r[i];
        }
        solution.clear();
        search(0);
        int time, m;
        tie(time, m) = solution[0];
		cout << "Case #" << t << ": " << n - m << " ";
        if (time == INF) {
            cout << "INDEFINITELY" << endl;
        } else {
            cout << time << endl;
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
