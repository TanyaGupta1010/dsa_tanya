class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        vector<bool> visited (nums.size(), false);
        solve(nums, ans, output, visited);
        return ans;
    }
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& output, vector<bool>& visited){
        if(output.size() == nums.size()){
            ans.push_back(output);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i]) continue;
            visited[i] = true;
            output.push_back(nums[i]);
            solve(nums, ans, output, visited);
            output.pop_back();
            visited[i] = false;
        }
    }
};