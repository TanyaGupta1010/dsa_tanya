class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int open = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else {
                // Ensure two consecutive ')'
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++;
                }

                // Match the pair with an opening '('
                if (open == 0) {
                    ans++;
                } else {
                    open--;
                }
            }
        }

        // Every unmatched '(' needs two ')'
        ans += 2 * open;

        return ans;
    }
};