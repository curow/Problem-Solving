#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) cout << 1 << endl;
    else if (n == 2 || n == 3) cout << "NO SOLUTION" << endl;
    else {
        for (int i = 1; i <= n / 2; ++i) cout << i * 2 << " ";
        for (int i = 1; i <= n / 2; ++i) cout << i * 2 - 1 << " ";
        if (n % 2) cout << n << endl;
        else cout << endl;
    }
    return 0;
}
