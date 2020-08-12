#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    size_t n = s.size();
    unordered_set<string> results;
    vector<bool> chosen(n, false);
    string permutation;
    function<void()> search;
    search = [&]() {
        if (permutation.size() == n) {
            results.insert(permutation);
        } else {
            for (size_t i = 0; i < n; ++i) {
                if (chosen[i]) continue;
                chosen[i] = true;
                permutation.push_back(s[i]);
                search();
                permutation.pop_back();
                chosen[i] = false;
            }
        }
    };
    search();
    cout << results.size() << endl;
    for (auto x : results) cout << x << endl;
    return 0;
}
