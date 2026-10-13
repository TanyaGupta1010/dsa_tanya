class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string output = "";
        solve(s, ans, output, 0, 0);
        return ans;
    }
    void solve(string s, vector<string>& ans, string output, int index,
               int parts) {
        if (parts == 4) {
            if (index == s.size()) {
                output.pop_back();
                ans.push_back(output);
            }
            return;
        }
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string segment = s.substr(index, len);
            if (len > 1 && segment[0] == '0')
                break;
            int num = stoi(segment);
            if (num > 255)
                break;
            solve(s, ans, output + segment + '.', index + len, parts + 1);
        }
    }
};