#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
const ll INF = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    ll distance[n + 1], prev[n + 1];
    for (int i = 1; i <= n; ++i) {
        distance[i] = INF;
        prev[i] = -1;
    }
    distance[1] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto e : edges) {
            ll a, b, w;
            tie(a, b, w) = e;
            if (distance[b] > distance[a] + w) {
                distance[b] = distance[a] + w;
                prev[b] = a;
            }
        }
    }
    ll buggy_node = -1;
    for (auto e : edges) {
        ll a, b, w;
        tie(a, b, w) = e;
        if (distance[b] > distance[a] + w) {
            buggy_node = b;
            prev[b] = a;
            break;
        }
    }
    if (buggy_node == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        ll temp = buggy_node;
        vector<ll> loop;
        set<ll> visited;
        ll last_node;
        do {
            if (visited.count(temp)) {
                last_node = temp;
                break;
            }
            loop.push_back(temp);
            visited.insert(temp);
            temp = prev[temp];
        } while (temp != -1);
        cout << last_node << " ";
        for (auto it = loop.rbegin(); it != loop.rend() && *it != last_node; ++it) {
            cout << *it << " ";
        }
        cout << last_node << endl;
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
