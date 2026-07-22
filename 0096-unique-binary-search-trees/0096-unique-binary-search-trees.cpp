class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int nodes = 1; nodes <= n; nodes++) {
            for (int left = 0; left < nodes; left++) {
                int right = nodes - left - 1;
                dp[nodes] += dp[left] * dp[right];
            }
        }

        return dp[n];
    }
};