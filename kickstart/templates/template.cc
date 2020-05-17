#include <iostream>
using namespace std;
int main() {
	int t, n, m;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> n >> m;
		cout << "Case #" << i << ": " << (n + m) << " " << (n * m) << endl;
	}
	return 0;
}
