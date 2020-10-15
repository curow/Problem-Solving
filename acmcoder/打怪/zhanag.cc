#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define col(n) cout << n <<endl
#define sz(x) int((x).size())
#define c(n) int n;cin >> n
#define ff(a,b,i) for (int (i) = a; (i) < (b); ++(i))
#define FF(a,b,i) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(a,b,i) for(int (i) = (a); (i) >= (b); --(i))
#define rof(a,b,i) for(int (i) = (a); (i) > (b); --(i))
#define vi vector<int>
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define pii pair<int,int>
#define MOD 1000000007
template<class T> bool checkMin(T &a, T b) {return a > b ? (a = b, true) : false;}
template<class T> bool checkMax(T &a, T b) {return a < b ? (a = b, true) : false;}
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 5;
int a[maxn], b[maxn];
int n;
void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
        b[i] = 1;
    }
    int ret = 0;
    for (int i = 0; i < n; i ++) {
        if (!a[i]) {
            ret += b[i];
        } else {
            b[i + 1] ++;
        }
    }
    printf("%d\n", ret);
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
