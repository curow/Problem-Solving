class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> hash;

        int cnt = 0, pre = 0;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            if (pre == k) cnt += 1;
            cnt += hash[pre - k];
            ++hash[pre];
        }
        return cnt;
    }
};
