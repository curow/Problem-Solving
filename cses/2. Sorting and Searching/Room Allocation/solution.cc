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
    vector<tuple<int, int, int>> info(n); // store {order index, start time, end time}
    vector<pair<int, int>> solution(n); // store {order index, room index}

    auto compare = [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second < b.second) {
            return true;
        } else if (a.second > b.second) {
            return false;
        } else {
            return a.first < b.first;
        }
    }; // sort first by end time, then by room label
    set<pair<int, int>, decltype(compare)> rooms(compare); // store {room index, end time}

    for (int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;
        info[i] = {i, s, e};
    }
    sort(info.begin(), info.end(), [](const auto &a, const auto &b) {
        return get<1>(a) < get<1>(b);
        int sa, ea, sb, eb;
        sa = get<1>(a), ea = get<2>(a);
        sb = get<1>(b), eb = get<2>(b);
        if (sa < sb) {
            return true;
        } else if (sa > sb) {
            return false;
        } else {
            return ea < eb;
        }
    }); // sort firt by start time, then by end time;

    int k = 0;
    for (auto [i, s, e] : info) {
        auto it = rooms.lower_bound({-1, s});
        if (it == rooms.begin()) {
            ++k;
            rooms.insert({k, e});
            solution[i] = {i, k};
        } else {
            it = prev(it);
            int j = (*it).first;
            rooms.erase(it);
            rooms.insert({j, e});
            solution[i] = {i, j};
        }
    }
    sort(solution.begin(), solution.end()); // sort by order index
    cout << k << endl;
    for (auto [_, j] : solution) {
        cout << j << " ";
    }
    cout << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
