class Solution {
public:
    vector<int> candidates;
    vector<vector<int>> output;
    vector<int> path;

    void dfs(int target, int start) {
        if (target == 0) {
            output.push_back(path);
            return;
        }
        if (start < size(candidates)) {
            int x = candidates[start];
            if (x > target) return;
            dfs(target, start + 1);
            path.push_back(x);
            dfs(target - x, start);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        dfs(target, 0);
        return output;
    }
};
