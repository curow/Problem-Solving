#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> y >> x;
        long long layer = max(x, y);
        long long mid = layer * layer - (layer - 1);
        long long offset = layer - min(x, y);
        long long dx = layer - x;
        long long dy = layer - y;
        if (dx > 0) cout << mid + (long long) pow(-1, layer) * offset << endl;
        else if (dy > 0) cout << mid + (long long) pow(-1, layer - 1) * offset << endl;
        else cout << mid << endl;
    }
    return 0;
}
