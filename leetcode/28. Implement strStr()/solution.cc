class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack == needle) return 0;
        int n = size(haystack), m = size(needle);
        for (int k = 0; k + m - 1 < n; ++k) {
            int i = 0;
            while (haystack[k + i] == needle[i]) ++i;
            if (i == m) return k;
        }
        return -1;
    }
};
