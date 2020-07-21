class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> f(nums.begin(), nums.end());
        for (int i = 1; i < f.size(); ++i)
            if (f[i - 1] > 0)
                f[i] += f[i - 1];
        return *max_element(f.begin(), f.end());
    }
};
