#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int rep = 0, best = 0;
    for (size_t i = 1; i < s.size(); ++i) {
        if (s[i - 1] == s[i]) ++rep;
        else rep = 0;
        best = max(best, rep);
    }
    cout << best + 1 << endl;
    return 0;
}
