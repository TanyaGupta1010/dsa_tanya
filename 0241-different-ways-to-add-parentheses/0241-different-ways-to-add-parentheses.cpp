class Solution {
public:
    vector<int> solve(string exp) {
        vector<int> ans;

        for (int i = 0; i < exp.size(); i++) {
            char ch = exp[i];

            if (ch == '+' || ch == '-' || ch == '*') {

                vector<int> left = solve(exp.substr(0, i));
                vector<int> right = solve(exp.substr(i + 1));

                for (int l : left) {
                    for (int r : right) {
                        if (ch == '+')
                            ans.push_back(l + r);
                        else if (ch == '-')
                            ans.push_back(l - r);
                        else
                            ans.push_back(l * r);
                    }
                }
            }
        }

        if (ans.empty())
            ans.push_back(stoi(exp));

        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};