class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& output, int n, int k, int index){
        //base-case
        if(k == 0){
            ans.push_back(output);
            return;
        }
        for(int i = index; i <= n; i++){
            output.push_back(i);
            solve(ans, output, n, k - 1, i + 1);
            output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
    vector<int> output;
    vector<vector<int>> ans;
    solve(ans, output, n, k, 1);
    return ans;    
    }

};