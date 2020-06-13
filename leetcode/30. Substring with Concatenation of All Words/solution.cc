class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> match;
        for (string word : words) {
            ++match[word];
        }
        /* for (auto const& [key, val] : match) { */
        /*     cout << key << ":" << val << endl; */
        /* } */
        vector<int> res;
        int word_size = size(words[0]);
        int substring_size = size(words) * word_size;
        for (int i = 0; i + substring_size - 1 < size(s); ++i) {
            unordered_map<string, int> running;
            bool finish_match = true;
            for (int j = 0; j + word_size - 1 < substring_size; j += word_size) {
                string word = s.substr(i + j, word_size);
                if (match[word] > running[word]) {
                    ++running[word];
                } else {
                    finish_match = false;
                    break;
                }
            }
            if (finish_match) res.push_back(i);
        }
        return res;
    }
};
