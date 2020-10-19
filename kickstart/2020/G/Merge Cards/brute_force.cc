#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll total_score;
ll case_count;
void dfs(vector<ll> &cards, ll score) {
    /* for (auto &x : cards) cout << x << " "; */
    /* cout << endl; */
    /* cout << "score: " << score << endl; */
    size_t len = cards.size();
    if (len == 1) {
        total_score += score;
        ++case_count;
        return;
    }
    for (size_t i = 0; i <= len - 2; ++i) {
        vector<ll> new_cards;
        ll merged_card = cards[i] + cards[i + 1];
        for (size_t j = 0; j < len; ++j) {
            if (j == i) new_cards.push_back(merged_card);
            else if (j == i + 1) continue;
            else new_cards.push_back(cards[j]);
        }
        dfs(new_cards, score + merged_card);
    }
}

void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<ll> cards(n);
        for (auto &x : cards) cin >> x;
        total_score = case_count = 0;
        dfs(cards, 0);
        long double expected_score = (long double)total_score / case_count;
        cout << fixed << setprecision(16);
        cout << "Case #" << t << ": " << expected_score << endl;
    }
}

int main() {
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
    ios_base::sync_with_stdio(false);
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
