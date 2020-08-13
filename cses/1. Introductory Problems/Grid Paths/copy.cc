#include <iostream>
#include <algorithm>
#include <string>
#include <chrono>
using namespace std;
const int dy[]{ 1, -1, 0 ,0 }, dx[]{ 0,0,-1,1 };
 
string s;
bool visited[9][9]; //1,1~7,1
 
int ans = 0;
void go(int cy, int cx, int k) {
	if (cy == 7 && cx == 1) {
		if (k == 48) ans++;
		return;
	}
 
	if (!visited[cy + 1][cx] && !visited[cy - 1][cx] && visited[cy][cx + 1] && visited[cy][cx - 1]) return;
	if (visited[cy + 1][cx] && visited[cy - 1][cx] && !visited[cy][cx + 1] && !visited[cy][cx - 1]) return;
 
	visited[cy][cx] = true;
 
	if (s[k] == '?') {
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i], nx = cx + dx[i];
			if (!visited[ny][nx] && ny >= 1 && nx >= 1 && ny < 8 && nx < 8)
				go(ny, nx, k + 1);
		}
	}
	else {
		int i;
		for (int j = 0; j < 4; j++)
			if (s[k] == "DULR"[j]) i = j;
		int ny = cy + dy[i], nx = cx + dx[i];
		if (!visited[ny][nx] && ny >= 1 && nx >= 1 && ny < 8 && nx < 8)
			go(ny, nx, k + 1);
	}
 
	visited[cy][cx] = false;
}
 
int main() {
    /* auto start = chrono::steady_clock::now(); */
	cin >> s;
	for (int i = 0; i <= 8; i++) visited[0][i] = visited[i][0] = visited[8][i] = visited[i][8] = 1;
	go(1, 1, 0);
	cout << ans << '\n';
    /* auto end = chrono::steady_clock::now(); */
    /* cout << "\nElapsed time in milliseconds : " */
    /*      << chrono::duration_cast<chrono::milliseconds>(end - start).count() */
    /*      << " ms\n"; */
}
