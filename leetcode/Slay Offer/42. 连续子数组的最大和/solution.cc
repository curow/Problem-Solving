class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            f[i] = max(nums[i], nums[i] + f[i - 1]);
        }
        return *max_element(f.begin(), f.end());
    }
};
