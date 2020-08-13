#include <bits/stdc++.h>

using namespace std;

const int n = 7;
string code;
unordered_map<char, pair<int, int>> go = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
bool visited[n + 2][n + 2];
int ans = 0;

void search(int py, int px, int p) {
    if (p == n * n - 1) {
        if (py == n && px == 1)
            ++ans;
        return;
    } else if (py == n && px == 1) {
        return;
    } else {
        bool up = !visited[py - 1][px], down = !visited[py + 1][px];
        bool left = !visited[py][px - 1], right = !visited[py][px + 1];
        if (up && down && !left && !right) return;
        if (left && right && !up && !down) return;
        if (code[p] == '?') {
            for (auto &[_, direction] : go) {
                int dy, dx;
                tie(dy, dx) = direction;
                int ny = py + dy, nx = px + dx;
                if (!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    search(ny, nx, p + 1);
                    visited[ny][nx] = false;
                }
            }
        } else {
            int dy, dx;
            tie(dy, dx) = go[code[p]];
            int ny = py + dy, nx = px + dx;
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                search(ny, nx, p + 1);
                visited[ny][nx] = false;
            }
        }        
    }
}

int main() {
    /* auto start = chrono::steady_clock::now(); */
    cin >> code;
    for (int k = 0; k <= n + 1; ++k) {
        visited[0][k] = visited[n + 1][k] = visited[k][0] = visited[k][n + 1] = true;
    }
    visited[1][1] = true;
    search(1, 1, 0);
    cout << ans << endl;
    /* auto end = chrono::steady_clock::now(); */
    /* cout << "\nElapsed time in milliseconds : " */
    /*      << chrono::duration_cast<chrono::milliseconds>(end - start).count() */
    /*      << " ms\n"; */
    /* return 0; */
}
