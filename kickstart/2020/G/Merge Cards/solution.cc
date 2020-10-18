#include <bits/stdc++.h>
using namespace std;

long double expected_score(vector<long long> &cards) {
    size_t len = cards.size();
    if (len <= 2) return accumulate(cards.begin(), cards.end(), 0);
    long double score = 0;
    for (size_t i = 0; i < len - 1; ++i) {
        vector<long long> new_cards;
        long long merged_card = cards[i] + cards[i + 1];
        for (size_t j = 0; j < len; ++j) {
            if (j == i) new_cards.push_back(merged_card);
            else if (j == i + 1) continue;
            else new_cards.push_back(cards[j]);
        }
        score += expected_score(new_cards) + merged_card;
    }
    return score / (len - 1);
}

void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<long long> cards(n);
        for (int i = 0; i < n; ++i) {
            cin >> cards[i];
        }
        cout << fixed << showpoint;
        cout << setprecision(16);
        cout << "Case #" << t << ": " << expected_score(cards) << endl;
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
