class Solution {
public:
    unordered_set<char> left{'(', '{', '['};
    unordered_map<char, char> pair{ {')', '('}, {'}', '{'}, {']', '['} };
    bool isValid(string s) {
        stack<char> sc;
        for (char c : s) {
            if (left.count(c)) sc.push(c);
            else {
                char op = pair[c];
                if (sc.empty()) return false;
                else if (sc.top() != op) return false;
                else sc.pop();
            }
        }
        return sc.empty();
    }
};
