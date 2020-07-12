#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef pair<char, set<char>> pcs;
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
        int r, c;
		cin >> r >> c;
        vector<vector<char>> matrix(r, vector<char>(c));
        map<char, set<char>> dependency;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> matrix[i][j];
                dependency[matrix[i][j]] = set<char>();
            }
        }

        for (int i = 0; i < r - 1; ++i) {
            for (int j = 0; j < c; ++j) {
                if (matrix[i][j] != matrix[i + 1][j]) {
                    dependency[matrix[i][j]].insert(matrix[i + 1][j]);
                }
            }
        }


        vector<pcs> vec;
        for (const auto &p : dependency) {
            vec.push_back(p);
        }


        string ans = "";
        while (!vec.empty()) {
            sort(vec.begin(), vec.end(),
                [](const pcs &a, const pcs &b) {
                    return a.second.size() > b.second.size();
                });

            pcs last = vec.back();
            if (last.second.size() != 0) {
                ans = "";
                break;
            } else {
                char x = last.first;
                ans += x;
                vec.pop_back();
                for (auto &p : vec) {
                    p.second.erase(x);
                }
            }
        }


		cout << "Case #" << t << ": " << (!ans.empty() ? ans : "-1") << endl;
	}
	return 0;
}
