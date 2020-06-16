class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if (n == 1) return res;
        n -= 1;
        while (n --) {
            string tmp;
            int i  = 0;
            while (i < size(res)) {
                int cnt = 1;
                int x = res[i] - '0';
                while (i + 1 < size(res) && res[i] == res[i + 1]) ++cnt, ++i;
                tmp += to_string(cnt) + to_string(x);
                ++i;
            }
            res = tmp;
        }
        return res;
    }
};
