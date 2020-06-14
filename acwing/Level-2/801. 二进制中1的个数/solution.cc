#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        int cnt = 0;
        while (x) {
            ++cnt;
            x -= x & -x;
        }
        cout << cnt << ' ';
    }
    cout << endl;
    return 0;
}
