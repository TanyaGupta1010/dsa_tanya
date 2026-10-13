class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        solve(n, ans, output, 0, 0);
        return ans;
    }
    void solve(int n, vector<string>& ans, string& output, int open, int close){
        if(output.size() == 2 * n){
            ans.push_back(output);
            return;
        }
        if(open < n){
            output.push_back('(');
            solve(n, ans, output, open + 1, close);
            output.pop_back();
        }
        if(close < open){
            output.push_back(')');
            solve(n, ans, output, open, close + 1);
            output.pop_back();
        }
    }
};