class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index,
               vector<int>& output) {
        // basecase
        if (index == nums.size()) {
            ans.push_back(output);
            return;
        }
        solve(nums, ans, index + 1, output);
        output.push_back(nums[index]);
        solve(nums, ans, index + 1, output);
        output.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, ans, 0, output);
        return ans;
    }
};