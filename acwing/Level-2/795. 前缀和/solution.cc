#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
