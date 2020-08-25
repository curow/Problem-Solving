#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 1e5 + 10, INF = 1e18;
int n, best_time, best_remain;
int e[N], r[N];
vector<int> subset;
bool search(int k) {
    if (k == n) {
        if (subset.empty()) return false;
        int m = subset.size();
        int s = 0;
        for (int i = 0; i < m; ++i) {
            s += e[subset[i]];
        }
        int time = s, i = 0;
        while (i < m) {
            if (s - e[subset[i]] >= r[subset[i]]) time += e[subset[i++]];
            else break;
        }
        if (i == n) {
            best_time = INF;
            best_remain = n;
            return true;
        } else if (i == m) {
            if (best_time == INF) {
                best_remain = max(best_remain, m);
            } else {
                best_time = INF;
                best_remain = m;
            }
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
        subset.clear();
        best_time = 0, best_remain = 0;
        search(0);
		cout << "Case #" << t << ": " << n - best_remain << " ";
        if (best_time == INF) {
            cout << "INDEFINITELY" << endl;
        } else {
            cout << best_time << endl;
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
