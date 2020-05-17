#include <iostream>
#include <vector>
using namespace std;

int isqrt(int n) {
	int x = n;
	int y = (x + 1) / 2;
	while (y < x) {
		x = y;
		y = (x + n / x) / 2;
	}
	return x;
}

int main() {
	int t, n;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		vector<int> array;
		int count = 0;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			int num;
			cin >> num;
			array.push_back(num);
		}
		for (int m = 0; m < n; ++m) {
			int s = 0;
			for (int k = m; k < n; ++k) {
				s += array[k];
				if (s >= 0) {
					int z = isqrt(s);
					if (z * z == s) {
						count += 1;
					}
				}
			}
		}
		cout << "Case #" << i << ": " << count << endl;
	}
	return 0;
}
