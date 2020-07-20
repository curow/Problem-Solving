#include <iostream>
#include <vector>

using namespace std;

const int N = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> f(n + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            f[j] = (f[j] + f[j - i]) % N;
        }
    }
    cout << f[n] << endl;
    return 0;
}
