
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Calculate semi-palindrome conversion cost
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    for (int i = 0; i < len / 2; i++) {
                        if (s[l + i] != s[r - i] &&
                            (i % d == (len - 1 - i) % d)) {
                            changes++;
                        }
                    }

                    // Check all groups using their positions
                    int curr = 0;

                    for (int x = 0; x < d; x++) {
                        int a = x;
                        int b = len - d + x;

                        while (a < b) {
                            if (s[l + a] != s[l + b])
                                curr++;

                            a += d;
                            b -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], curr);
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int p = 0; p <= i - 2; p++) {
                    if (dp[p][j - 1] == INF) continue;

                    dp[i][j] = min(dp[i][j],
                        dp[p][j - 1] + cost[p][i - 1]);
                }
            }
        }

        return dp[n][k];
    }
};
