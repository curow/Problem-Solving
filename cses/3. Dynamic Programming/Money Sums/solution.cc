#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
#ifdef DEBUG
    freopen("input.txt", "r", stdin);    // redirects standard input
    freopen("output.txt", "w", stdout);  // redirects standard output
#endif

    // solve the problem
    int n;
    cin >> n;
    set<int> sums;
    vector<int> temp;
    temp.reserve(100 * 1000 + 10);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        temp.clear();
        temp.push_back(x);
        for (const int s : sums) temp.push_back(s + x);
        for (const int s : temp) sums.insert(s);
    }
    cout << sums.size() << endl;
    for (const int s : sums) cout << s << " ";
    cout << endl;

#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
