class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        const int n = nums.size();
        prefix.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
