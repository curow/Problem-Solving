#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n;
struct Project {
    int start, end, reward;
    bool operator< (const Project &rhs) {
        if (start < rhs.start) {
            return true;
        } else if (start > rhs.start) {
            return false;
        } else if (end < rhs.end) {
            return true;
        } else if (end > rhs.end) {
            return false;
        } else {
            return reward > rhs.reward;
        }
    }
} projects[N];

int best = 0;
vector<int> subset;
void search(int k, int last) {
    if (k == n) {
        int s = 0;
        for (int x : subset) {
            s += projects[x].reward;
        }
        best = max(best, s);
        return;
    }
    if (projects[k].start > last) {
        subset.push_back(k);
        search(k + 1, projects[k].end);
        subset.pop_back();
    }
    search(k + 1, last);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }
    sort(projects, projects + n);
    search(0, 0);
    cout << best << endl;
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
