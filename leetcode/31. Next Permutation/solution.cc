class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (size(nums) <= 1) return;
        int r = size(nums) - 1, l = r;
        while (l > 0 && nums[l - 1] >= nums[l]) --l;
        if (l == 0) reverse(nums.begin(), nums.end());
        else {
            int x = nums[l - 1];
            int i = l, j = r;
            while (i < j) {
                int mid = (i + j + 1) >> 1;
                if (nums[mid] > x) i = mid;
                else j = mid - 1;
            }
            swap(nums[i], nums[l - 1]);
            reverse(nums.begin() + l, nums.end());
        }
    }
};
