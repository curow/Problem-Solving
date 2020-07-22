class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        vector<int> f(n);
        for (int i = 0; i < 2; ++i) f[i] = cost[i];
        for (int i = 2; i < n; ++i) {
            f[i] = min(f[i - 1], f[i - 2]) + cost[i];
        }
        return min(f[n - 1], f[n - 2]);
    }
};
