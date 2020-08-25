#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 1e5 + 10, INF = 1e18;
vector<int> e(N), r(N), v(N);
vector<int> subset;
vector<pair<int, int>> solution;
int n;
void search(int k) {
    if (k == n) {
        if (subset.empty()) return;
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
        if (i == 2 * m) solution.push_back({INF, m});
        else solution.push_back({time, m});
    } else {
        subset.push_back(k);
        search(k + 1);
       subset.pop_back();
        search(k + 1);
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
        sort(solution.begin(), solution.end(), [](const auto &a, const auto &b) {
            if (a.first > b.first) {
                return true;
            } else if (a.first < b.first) {
                return false;
            } else if (a.second >= b.second) {
                return true;
            } else {
                return false;
            }
        });
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
 
