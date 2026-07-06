class Solution {
public:
    bool valid(string part) {
        if (part.size() > 3)
            return false;
        if (part.size() > 1 && part[0] == '0')
            return false;
        int num = stoi(part);
        return num <= 255;
    }
    void solve(vector<string>& ans, string& s, string output, int index,
               int parts) {
        // base-case
        if (index == s.size() && parts == 4) {
            output.pop_back();
            ans.push_back(output);
            return;
        }
        if (parts == 4)
            return;
        for (int len = 1; len < 4 && index + len <= s.size(); len++) {
            string part = s.substr(index, len);
            if (valid(part)) {
                solve(ans, s, output + part + ".", index + len, parts + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(ans, s, "", 0, 0);
        return ans;
    }
};