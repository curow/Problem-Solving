class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = size(nums);
        int slow = 0, fast = 0;
        while (slow < n && fast < n) {
            while (fast < n && nums[slow] == nums[fast]) ++fast;
            if (fast < n && slow + 1 < n) {
                nums[++slow] = nums[fast];
            } else {
                break;
            }
        }
        return slow + 1;
    }
};
