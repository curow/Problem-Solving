#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const double INF = 2e9;

bool available[N];
int x[N], y[N];

int n;
double best;

void search(int k, double s) {
    if (k == n) {
        best = min(best, s);
        return;
    }
    int i = 0;
    while (i < 2 * n && !available[i]) ++i;
    available[i] = false;
    for (int j = i + 1; j < 2 * n; ++j) {
        if (available[j]) {
            available[j] = false;
            double dist = hypot(x[i] - x[j], y[i] - y[j]);
            search(k + 1, s + dist);
            available[j] = true;
        }
    }
    available[i] = true;
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
    int rounds = 0;
    while (scanf("%d", &n), n != 0) {
        for (int i = 0; i < 2 * n; ++i) {
            scanf("%*s %d %d", &x[i], &y[i]);
            available[i] = true;
        }
        best = INF;
        search(0, 0);
        printf("Case %d: %.2f\n", ++rounds, best);
    }

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
