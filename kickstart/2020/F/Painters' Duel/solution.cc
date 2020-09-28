#include <bits/stdc++.h>
using namespace std;

const int S = 10, INF = 1e9;
bool painted[S + 1][2 * S];
int s;

vector<pair<int, int>> neighbors(const pair<int, int> x) {
    int r, p;
    tie(r, p) = x;
    vector<pair<int, int>> v;
    if (p - 1 >= 1 && !painted[r][p - 1])
        v.push_back({r, p - 1});
    if (p + 1 <= 2 * r - 1 && !painted[r][p + 1])
        v.push_back({r, p + 1});
    if (p % 2 == 0 && r - 1 >= 1 && p - 1 >= 1 && !painted[r - 1][p - 1])
        v.push_back({r - 1, p - 1});
    if (p % 2 == 1 && r + 1 <= s && p + 1 <= 2 * (r + 1) - 1 && !painted[r + 1][p + 1])
        v.push_back({r + 1, p + 1});
    return v;
}

int search(const pair<int, int> a, const pair<int, int> b) {
    /* cout << "\na: " << a.first << a.second << endl; */
    /* cout << "b: " << b.first << b.second << endl; */
    auto u = neighbors(a), v = neighbors(b);
    if (u.empty() && v.empty()) {
        /* cout << "a and b neighbor empty" << endl; */
        return 0;
    } else if (u.empty()) {
        /* cout << "a neighbor empty" << endl; */
        int worst_score = INF;
        for (const auto &y : v) {
            painted[y.first][y.second] = true;
            int score = search(a, y);
            if (score < worst_score) {
                worst_score = score;
            }
            painted[y.first][y.second] = false;
        }
        return -1 + worst_score;
    } else if (v.empty()) {
        /* cout << "b neighbor empty" << endl; */
        int best_score = -INF;
        for (const auto &x : u) {
            painted[x.first][x.second] = true;
            int score = search(x, b);
            if (score > best_score) {
                best_score = score;
            }
            painted[x.first][x.second] = false;
        }
        return 1 + best_score;
    }
    int best_score = -INF;
    for (const auto &x : u) {
        painted[x.first][x.second] = true;
        vector<pair<int, int>> v = neighbors(b);
        if (v.empty()) {
            int score = 1 + search(x, b);
            if (score > best_score) {
                best_score = score;
            }
        } else {
            int worst_score = INF;
            for (const auto &y : v) {
                painted[y.first][y.second] = true;
                int score = search(x, y);
                if (score < worst_score) {
                    worst_score = score;
                }
                painted[y.first][y.second] = false;
            }
            int score = worst_score;
            if (score > best_score) {
                best_score = score;
            }
        }
        painted[x.first][x.second] = false;
    }
    return best_score;
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
            for (int j = 1; j <= 2 * i - 1; ++j) {
                painted[i][j] = false;
            }
        }
        for (int i = 0; i < c; ++i) {
            int r, p;
            cin >> r >> p;
            painted[r][p] = true;
        }
        pair<int, int> a = {ra, pa}, b = {rb, pb};
		cout << "Case #" << t << ": " << search(a, b) << endl;
	}

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
