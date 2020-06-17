class Solution {
public:
    vector<int> candidates;
    vector<int> path;
    vector<vector<int>> output;
    int n;

    void dfs(int target, int start) {
        if (target == 0) {
            output.push_back(path);
        }
        if (start < n) {
            int x = candidates[start];
            if (x > target) return;

            path.push_back(x);
            dfs(target - x, start + 1);
            path.pop_back();

            // move to the last index of x
            while (start + 1 < n && candidates[start] == candidates[start + 1]) {
                ++start;
            }
            dfs(target, start + 1);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        n = size(candidates);
        dfs(target, 0);
        return output;
    }
};
