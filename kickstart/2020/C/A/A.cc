#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
        int n, k;
		cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) cin >> A[i];

        int i = 0, j, cnt = 0;
        while (i <= n - k) {
            while (i <= n - k && A[i] != k) ++i;
            if (i > n - k) {
                break;
            }

            j = i;
            for (int z = k; z > 0; --z) {
                if (A[j] == z) ++j;
                else break;
            }
            if (j - i == k) {
                ++cnt;
                i = j;
            } else {
                ++i;
            }
        }
		cout << "Case #" << t << ": " << cnt << endl;
	}
	return 0;
}
