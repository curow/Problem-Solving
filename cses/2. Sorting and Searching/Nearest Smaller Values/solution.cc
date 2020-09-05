#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10;
int a[N];

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    stack<int> s;
    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        while (!s.empty()) {
            int j = s.top();
            if (a[j] >= x) {
                s.pop();
            } else {
                break;
            }
        }
        if (s.empty()) cout << 0 << " ";
        else cout << s.top() << " ";
        s.push(i);
    }

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
