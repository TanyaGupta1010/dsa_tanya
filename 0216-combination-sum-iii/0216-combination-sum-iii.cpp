class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& output, int k, int target, int index){
        //base-case
        if(target == 0 && k == 0){
            ans.push_back(output);
            return;
        }
        if(target < 0 && k < 0){
            return;
        }
        for(int i = index; i <= 9; i++){
            if(i > target){
                break;
            }
            output.push_back(i);
            solve(ans, output, k - 1, target - i, i + 1);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(ans, output, k, n, 1);
        return ans;
    }
};