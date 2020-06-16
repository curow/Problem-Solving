class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = size(nums) - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }
        int k = l;
        auto find = [&](int l, int r) -> int {
            if (l > r) return -1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (nums[mid] <= target) l = mid;
                else r = mid - 1;
            }
            if (nums[l] == target) return l;
            return -1;
        };
        if (target < nums[0]) return find(k + 1, size(nums) - 1);
        else return find(0, k);
    }
};
