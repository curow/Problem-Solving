class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = size(nums);
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < n && nums[i] != val) ++i;
            while (j >= 0 && nums[j] == val) --j;
            if (i < j) swap(nums[i], nums[j]);
        }
        return i;
    }
};
