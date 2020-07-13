#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
        int n;
		cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        int breaking_num = -1, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] > breaking_num) {
                breaking_num = v[i];
                if (i == n - 1 || v[i] > v[i + 1]) {
                    ++cnt;
                }
            }
        }

		cout << "Case #" << t << ": " << cnt << endl;
	}
	return 0;
}
