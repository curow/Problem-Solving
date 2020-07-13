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

        int cnt = 0;
        int previousRecord = -1;
        for (int i = 0; i < n; ++i) {
            bool greaterThanPreviousDays = i == 0 || v[i] > previousRecord;
            bool greaterThanFollowingDay = i == n - 1 || v[i] > v[i + 1];
            if (greaterThanPreviousDays && greaterThanFollowingDay) {
                ++cnt;
            }
            previousRecord = max(previousRecord, v[i]);
        }
		cout << "Case #" << t << ": " << cnt << endl;
	}
	return 0;
}
