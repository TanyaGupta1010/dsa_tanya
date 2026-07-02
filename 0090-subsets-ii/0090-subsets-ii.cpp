class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> output;
        solve(nums, ans, output, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    void solve(vector<int>& nums, set<vector<int>>& ans, vector<int>& output, int index){
        //basecase
        if(index == nums.size()){
            ans.insert(output);
            return;
        }
        solve(nums, ans, output, index + 1);
        output.push_back(nums[index]);
        solve(nums, ans, output, index + 1);
        output.pop_back();
    }
};