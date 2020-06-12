class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = size(nums);
        int i = 0;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                --n;
            } else {
                ++i;
            }
        }
        return i;
    }
};
