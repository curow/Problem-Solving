#include <bits/stdc++.h>
using namespace std;

const int S = 10, INF = 1e9;
bool painted[S + 1][2 * S];
int s;

vector<pair<int, int>> possible_moves(const pair<int, int> x) {
    int r, p;
    tie(r, p) = x;
    vector<pair<int, int>> moves;
    if (p - 1 >= 1 && !painted[r][p - 1])
        moves.push_back({r, p - 1});
    if (p + 1 <= 2 * r - 1 && !painted[r][p + 1])
        moves.push_back({r, p + 1});
    if (p % 2 == 0 && r - 1 >= 1 && p - 1 >= 1 && !painted[r - 1][p - 1])
        moves.push_back({r - 1, p - 1});
    if (p % 2 == 1 && r + 1 <= s && p + 1 <= 2 * (r + 1) - 1 && !painted[r + 1][p + 1])
        moves.push_back({r + 1, p + 1});
    return moves;
}

int search(bool a_should_move, pair<int, int> a, pair<int, int> b) {
    auto a_moves = possible_moves(a), b_moves = possible_moves(b);
    if (a_moves.empty() && b_moves.empty()) return 0;
    if (a_should_move) {
        if (a_moves.empty()) return search(false, a, b);
        int max_score = -INF;
        for (pair<int, int> x : a_moves) {
            painted[x.first][x.second] = true;
            int score = search(false, x, b);
            max_score = max(max_score, score);
            painted[x.first][x.second] = false;
        }
        return max_score + 1;
    } else {
        if (b_moves.empty()) return search(true, a, b);
        int min_score = INF;
        for (pair<int, int> x : b_moves) {
            painted[x.first][x.second] = true;
            int score = search(true, a, x);
            min_score = min(min_score, score);
            painted[x.first][x.second] = false;
        }
        return min_score - 1;
    }
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
        painted[ra][pa] = painted[rb][pb] = true;
        for (int i = 0; i < c; ++i) {
            int r, p;
            cin >> r >> p;
            painted[r][p] = true;
        }
        pair<int, int> a = {ra, pa}, b = {rb, pb};
		cout << "Case #" << t << ": " << search(true, a, b) << endl;
	}

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
