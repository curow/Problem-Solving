#include <bits/stdc++.h>

using namespace std;

int main() {
    string source;
    cin >> source;
    size_t n = source.size();
    set<string> res;
    function<void(string, string)> search;
    search = [&](string build, string remain) {
        if (build.size() == n) {
            res.insert(build);
        } else {
            for (size_t i = 0; i < remain.size(); ++i) {
                string next_remain = remain;
                next_remain.erase(i, 1);
                search(build + remain[i], next_remain);
            }
        }
    };
    search("", source);
    cout << res.size() << endl;
    for (string s : res) {
        cout << s << endl;
    }
    return 0;
}
