class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best, sum;
        best = sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum = max(nums[i], sum + nums[i]);
            best = max(best, sum);
        }
        return best;
    }
};
