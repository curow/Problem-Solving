#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5000;
const ll INF = 2e18;
int n, a[N];
bool ready[N][N];
pair<int, ll> value[N][N];

pair<int, ll> getBestScore(int l, int r) {
    if (l == r) return {l, a[l]};
    if (ready[l][r]) return value[l][r];
    if (r - l == 1) {
        if (a[l] > a[r]) {
            value[l][r] = {l, a[l]};
        } else {
            value[l][r] = {r, a[r]};
        }
        ready[l][r] = true;
        return value[l][r];
    }

    ll best_score = -INF, score;
    int best_choice;

    // choose l
    auto nc1 = getBestScore(l + 1, r);
    if (nc1.first == l + 1) {
        score = a[l] + getBestScore(l + 2, r).second;
    } else {
        score = a[l] + getBestScore(l + 1, r - 1).second;
    }
    if (best_score < score) {
        best_score = score;
        best_choice = l;
    }

    // choose r
    auto nc2 = getBestScore(l, r - 1);
    if (nc2.first == l) {
        score = a[r] + getBestScore(l + 1, r - 1).second;
    } else {
        score = a[r] + getBestScore(l, r - 2).second;
    }
    if (best_score < score) {
        best_score = score;
        best_choice = r;
    }

    ready[l][r] = true;
    value[l][r] = {best_choice, best_score};
    return value[l][r];
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << getBestScore(0, n - 1).second << endl;
}

int main() {
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);  // redirects standard input
    /* freopen("output.txt", "w", stdout); // redirects standard output */
#endif
    // solve the problem
    solve();
#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
