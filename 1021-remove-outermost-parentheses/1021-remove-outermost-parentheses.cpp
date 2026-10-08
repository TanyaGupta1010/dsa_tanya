class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth = 0;

        for(char c : s) {
            if(c == '(') {
                depth++;

                // Not outermost
                if(depth > 1)
                    ans += c;
            }
            else {
                depth--;

                // Not outermost
                if(depth > 0)
                    ans += c;
            }
        }

        return ans;
    }
};