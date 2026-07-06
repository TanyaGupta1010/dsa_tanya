class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(vector<vector<string>>& ans, vector<string>& output, string& s,
               int index) {
        // base-case
        if (index == s.size()) {
            ans.push_back(output);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                output.push_back(s.substr(index, i - index + 1));
                solve(ans, output, s, i + 1);
                output.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(ans, output, s, 0);
        return ans;
    }
};