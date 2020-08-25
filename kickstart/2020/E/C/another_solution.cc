#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 1e5 + 10, INF = 1e18;
int n;
int e[N], r[N];
vector<int> subset;
vector<pair<int, int>> solution;
bool search(int k) {
    if (k == n) {
        if (subset.empty()) return false;
        int m = subset.size();
        int s = 0;
        for (int i = 0; i < m; ++i) {
            s += e[subset[i]];
        }
        int time = s, i = 0;
        while (i <= m) {
            if (s - e[subset[i % m]] >= r[subset[i % m]]) time += e[subset[i % m]];
            else break;
            ++i;
        }
        if (i == n + 1) {
            solution.push_back({INF, n});
            return true;
        } else if (i == m + 1) {
            solution.push_back({INF, m});
            return false;
        } else {
            solution.push_back({time, m});
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
        solution.clear();
        bool ok = search(0);
        if (ok) {
            cout << "Case #" << t << ": " << 0 << " " << "INDEFINITELY" << endl;
            continue;
        }
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
