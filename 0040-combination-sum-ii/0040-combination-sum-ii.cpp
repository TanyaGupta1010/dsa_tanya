class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& output,
               vector<int>& candidates, int target, int index) {
        if (target < 0)
            return;
        // base-case
        if (target == 0) {
            ans.push_back(output);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            output.push_back(candidates[i]);
            solve(ans, output, candidates, target - candidates[i], i + 1);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans, output, candidates, target, 0);
        return ans;
    }
};