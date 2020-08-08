#include <bits/stdc++.h>

using namespace std;

const int N = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int res = 1;
    while (n--) {
        res = (res << 1) % N;
    }
    cout << res << endl;
    return 0;
}
