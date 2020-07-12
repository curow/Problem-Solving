#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
        int n, k;
		cin >> n >> k;
        vector<int> A(n);
        for (int j = 0; j < n; ++j) cin >> A[j];

        int cnt = 0, index = 0, cur = k;
        while (index < n) {
            if (cur == 0) {
                ++cnt;
                cur = k;
            }

            if (A[index] == cur) {
                --cur;
            } else if (A[index] == k){
                cur = k - 1;
            } else {
                cur = k;
            }

            ++index;
        }
        if (cur == 0) ++cnt;

		cout << "Case #" << i << ": " << cnt << endl;
	}
	return 0;
}
