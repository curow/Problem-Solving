#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    int n;
    cin >> n;
    array<int, 3> info[n]; // store [start time, end time, order index]
    for (int i = 0; i < n; ++i) {
        cin >> info[i][0] >> info[i][1];
        info[i][2] = i;
    }
    sort(info, info + n);
    int ans[n]; // store room index for each order
    set<array<int, 2>> room; // store [end time, room index]
    for (auto &x : info) {
        int start = x[0], end = x[1], i = x[2];
        auto it = room.lower_bound({start});
        if (it == room.begin()) {
            ans[i] = room.size() + 1;
        } else {
            it = prev(it);
            room.erase(it);
            ans[i] = (*it)[1];
        }
        room.insert({end, ans[i]});
    }
    cout << room.size() << endl;
    for (auto k : ans) cout << k << " ";

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
