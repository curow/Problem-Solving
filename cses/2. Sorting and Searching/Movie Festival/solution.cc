#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for (auto &[s, e] : movies) cin >> s >> e;
    auto comp = [](const auto &a, const auto &b) {
        return a.second < b.second;
    }; // sort by ending time
    sort(movies.begin(), movies.end(), comp);
    int count = 0, last = 0;
    for (auto &[s, e] : movies) {
        if (s >= last) {
            last = e;
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}
