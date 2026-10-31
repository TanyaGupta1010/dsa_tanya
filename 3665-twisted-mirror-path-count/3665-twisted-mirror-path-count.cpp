class Solution {
public:
    static const int MOD = 1e9 + 7;

    int m, n;
    vector<vector<int>> grid;

    int resolve(int r, int c, int dir) {

        if (r < 0 || r >= m || c < 0 || c >= n)
            return -1;

        // Normal cell
        if (grid[r][c] == 0) {
            return r * n + c;
        }

        // Mirror
        // Moving right -> turn down
        if (dir == 0) {
            return resolve(r + 1, c, 1);
        }

        // Moving down -> turn right
        return resolve(r, c + 1, 0);
    }

    int uniquePaths(vector<vector<int>>& g) {

        grid = g;
        m = grid.size();
        n = grid[0].size();

        vector<vector<long long>> dp(
            m, vector<long long>(n, 0)
        );

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1 || dp[i][j] == 0)
                    continue;

                long long ways = dp[i][j];

                // Move RIGHT
                int x = resolve(i, j + 1, 0);

                if (x != -1) {
                    int r = x / n;
                    int c = x % n;

                    dp[r][c] =
                        (dp[r][c] + ways) % MOD;
                }

                // Move DOWN
                x = resolve(i + 1, j, 1);

                if (x != -1) {
                    int r = x / n;
                    int c = x % n;

                    dp[r][c] =
                        (dp[r][c] + ways) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};