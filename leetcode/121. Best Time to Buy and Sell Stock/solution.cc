class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n <= 1) return 0;
        vector<int> f(n, 0);
        for (int i = 1; i < n; ++i) {
            f[i] = prices[i] - prices[i - 1];
            if (f[i - 1] > 0) {
                f[i] += f[i - 1];
            }
        }
        return *max_element(f.begin(), f.end());
    }
};
