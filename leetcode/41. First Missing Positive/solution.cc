class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = size(nums);
        unordered_set<int> hash;
        int res = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0) continue;
            hash.insert(nums[i]);
            while(hash.count(res)) {
                ++res;
            }
        }
        return res;
    }
};
