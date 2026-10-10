class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, ans, output, 0);
        return ans;
    }
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, int index){
        if(index == nums.size()){
            ans.push_back(output);
            return;
        }
        solve(nums, ans, output, index + 1);
        output.push_back(nums[index]);
        solve(nums, ans, output, index + 1);
        output.pop_back();
    }
};