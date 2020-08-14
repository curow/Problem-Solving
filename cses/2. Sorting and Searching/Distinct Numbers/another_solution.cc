#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    cout << s.size() << endl;
    return 0;
}
