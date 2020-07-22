class Solution {
public:
    int massage(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        vector<int> f(n);
        for (int i = 0; i < n; ++i) {
            f[i] = max(nums[i] + (i >= 2 ? f[i - 2] : 0), i >= 1 ? f[i - 1] : 0);
        }
        return f[n - 1];
    }
};
