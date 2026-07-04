class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& output,
               vector<int>& candidates, int target, int index) {
        // base-case
        if (target == 0) {
            ans.push_back(output);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target)
                break;
            output.push_back(candidates[i]);
            // target -= candidates[i];
            solve(ans, output, candidates, target - candidates[i], i);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans, output, candidates, target, 0);
        return ans;
    }
};