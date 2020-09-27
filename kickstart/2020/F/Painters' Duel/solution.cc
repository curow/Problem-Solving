#include <bits/stdc++.h>
using namespace std;

const int S = 10, INF = 1e9;
bool painted[S + 1][2 * S];
int s;

vector<pair<int, int>> next(int r, int p) {
    vector<pair<int, int>> v;
    if (p > 1 && !painted[r][p - 1])
        v.push_back({r, p - 1});
    if (p < 2 * s - 1 && !painted[r][p + 1])
        v.push_back({r, p + 1});
    if (p % 2 == 0 && r - 1 >= 1 && p - 1 >= 1 && !painted[r - 1][p - 1])
        v.push_back({r - 1, p - 1});
    if (p % 2 == 1 && r + 1 <= s && p + 1 <= 2 *s - 1 && !painted[r + 1][p + 1])
        v.push_back({r + 1, p + 1});
    return v;
}

tuple<int, int, int> search(int r1, int p1, int r2, int p2) {
    vector<pair<int, int>> v1 = next(r1, p1);
    if (v1.empty()) return {0, r1, p1};
    int bc1 = 0, br1 = r1, bp1 = p1;
    for (const auto &pos : v1) {
        int r3, p3, r4, p4, r5, p5;
        tie(r3, p3) = pos;
        painted[r3][p3] = true;
        int c1, c2;
        tie(c2, r4, p4) = search(r2, p2, r3, p3);
        tie(c1, r5, p5) = search(r3, p3, r4, p4);
        c1 += 1;
        if (bc1 < c1) {
            bc1 = c1;
            br1 = r3;
            bp1 = p3;
        }
        painted[r3][p3] = false;
    }
    return {bc1, br1, bp1};
}

int main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    #ifdef DEBUG
    freopen("input.txt", "r", stdin); // redirects standard input
    freopen("output.txt", "w", stdout); // redirects standard output
    #endif

    // solve the problem
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
        int ra, pa, rb, pb, c;
        cin >> s >> ra >> pa >> rb >> pb >> c;
        for (int i = 1; i <= s; ++i) {
            for (int j = 1; j <= 2 * s - 1; ++j) {
                painted[i][j] = false;
            }
        }
        for (int i = 0; i < c; ++i) {
            int a, b;
            cin >> a >> b;
            painted[a][b] = true;
        }
        int ca, cb;
        tie(ca, ra, pa) = search(ra, pa, rb, pb);
        tie(cb, rb, pb) = search(rb, pb, ra, pa);
		cout << "Case #" << t << ": " << ca - cb << endl;
	}

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
