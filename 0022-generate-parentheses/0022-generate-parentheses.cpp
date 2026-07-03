class Solution {
public:
    void solve(vector<string> &ans, string &output, int open, int close, int n){
        //basecase
        if(output.size() == 2*n){
            ans.push_back(output);
            return;
        }
        if(open < n){
            output.push_back('(');
            solve(ans, output, open + 1, close, n);
            output.pop_back();
        }
        if(close < open){
            output.push_back(')');
            solve(ans, output, open, close + 1, n);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        solve(ans, output, 0, 0, n);
        return ans;
    }
};