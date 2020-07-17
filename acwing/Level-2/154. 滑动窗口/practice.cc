#include <iostream>
#include <vector>
#include <deque>
#include <functional>

using namespace std;

void monotonic_scan(const vector<int> &a, int k, function<bool(int, int)> better) {
    vector<int> res;
    deque<int> mono;

    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (i >= k && mono.front() == a[i - k]) {
            mono.pop_front();
        }
        while (!mono.empty()) {
            if (better(a[i], mono.back())) {
                mono.pop_back();
            } else {
                break;
            }
        }
        mono.push_back(a[i]);
        if (i >= k - 1) {
            res.push_back(mono.front());
        }
    }

    for (const auto &x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    monotonic_scan(a, k, less<int>());
    monotonic_scan(a, k, greater<int>());
    return 0;
}
