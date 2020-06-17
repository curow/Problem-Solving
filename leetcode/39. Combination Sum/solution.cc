class Solution {
public:
    vector<vector<int>> output;

    void dfs(vector<int> candidates, vector<int> build, int target) {
        if (target == 0) {
            output.push_back(build);
            return;
        } else if (candidates.empty()) {
            return;
        }
        int x = candidates.back();
        if (x <= target) {
            build.push_back(x);
            dfs(candidates, build, target - x);
            build.pop_back();
        }
        candidates.pop_back();
        dfs(candidates, build, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, {}, target);
        return output;
    }
};
