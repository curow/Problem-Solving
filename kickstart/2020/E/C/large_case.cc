#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 1e5 + 10;
int e[N], r[N];

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
        int n;
		cin >> n;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> e[i] >> r[i];
            s += e[i];
        }
        auto compare = [](int a, int b) {
            return e[a] + r[a] < e[b] + r[b];
        };
        priority_queue<int, vector<int>, decltype(compare)> toys(compare);
        int cur_time = s, pop_cnt = 0;
        int max_time = s, corr_pop = 0;
        for (int i = 0; i < n; ++i) {
            toys.push(i);
            cur_time += e[i];
            while(!toys.empty()) {
                int j = toys.top();
                if (s >= e[j] + r[j]) {
                    break;
                } else {
                    toys.pop();
                    s -= e[j];
                    cur_time -= 2 * e[j];
                    ++pop_cnt;
                }
            }
            if (cur_time > max_time) {
                max_time = cur_time;
                corr_pop = pop_cnt;
            }
        }
		cout << "Case #" << t << ": ";
        if (!toys.empty()) {
            cout << pop_cnt << " " << "INDEFINITELY" << endl;
        } else {
            cout << corr_pop << " " << max_time << endl;
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
