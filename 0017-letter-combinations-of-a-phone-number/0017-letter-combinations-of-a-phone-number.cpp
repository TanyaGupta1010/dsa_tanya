class Solution {
public:
    void solve(vector<string> &ans, string &output, vector<string> mapping, int index, string digits){
        //basecase
        if(index == digits.size()){
            ans.push_back(output);
            return;
        }
        int number = digits[index] - '0';
        string value = mapping[number];
        for(int i = 0; i < value.size(); i++){
            output.push_back(value[i]);
            solve(ans, output, mapping, index + 1, digits);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        string output = "";
        vector<string> mapping {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(ans, output, mapping, 0, digits);
        return ans;
    }
};