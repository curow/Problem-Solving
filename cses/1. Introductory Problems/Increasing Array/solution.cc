#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, last;
    cin >> n >> last;
    long long turns = 0;
    while (--n) {
        int current;
        cin >> current;
        if (current < last) turns += last - current;
        else last = current;
    }
    cout << turns << endl;
    return 0;
}
