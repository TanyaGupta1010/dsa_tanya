class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& output, vector<bool>& visited, vector<int>& nums){
        //base-case
        if(output.size() == nums.size()){
            ans.push_back(output);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i]) continue;
            visited[i] = true;
            output.push_back(nums[i]);
            solve(ans, output, visited, nums);
            output.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        vector<bool> visited(nums.size(), false);
        solve(ans, output, visited, nums);
        return ans;
    }
};