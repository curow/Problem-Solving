class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = size(nums) - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] >= target) return l;
        else return size(nums);
    }
};
