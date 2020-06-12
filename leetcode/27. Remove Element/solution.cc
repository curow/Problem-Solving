class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = size(nums);
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && nums[j] == val) ++j;
            if (j < n) {
                nums[i] = nums[j];
                ++i;
                ++j;
            }
        }
        return i;
    }
};
