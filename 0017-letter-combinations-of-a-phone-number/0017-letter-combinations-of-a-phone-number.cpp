class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, ans, output, mapping, 0);
        return ans;
    }
    void solve(string digits, vector<string>& ans, string& output, vector<string>& mapping, int index){
        if(output.size() == digits.size()){
            ans.push_back(output);
            return;
        }
        int num = digits[index] - '0';
        string value = mapping[num];
        for(int i = 0; i < value.size(); i++){
            output.push_back(value[i]);
            solve(digits, ans, output, mapping, index + 1);
            output.pop_back();
        }
    }
};