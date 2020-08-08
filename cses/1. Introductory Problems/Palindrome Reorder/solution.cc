#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<char, int> hash;
    int cnt = 0;
    char x, odd_val = ' ';
    while (cin >> x) {
        ++hash[x];
        ++cnt;
    }
    bool valid = true;
    int odd = 0;
    for (auto &[c, v] : hash) {
        if (v % 2) {
            ++odd;
            odd_val = c;
            if (cnt % 2 == 0 || odd >= 2) {
                valid = false;
                break;
            }
        } 
    }
    if (valid) {
        string res = "";
        for (auto &[c, v] : hash) {
            res += string(v / 2, c);
        }
        string temp(res.rbegin(), res.rend());
        if (odd_val != ' ') res += odd_val;
        res += temp;
        cout << res << endl;
    } else {
        cout << "NO SOLUTION" << endl;
    }
    return 0;
}
