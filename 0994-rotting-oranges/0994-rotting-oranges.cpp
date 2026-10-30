class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> q;
        int fresh = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();
            ans = max(ans, t);
            if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1) {
                visited[i - 1][j] = true;
                q.push({{i - 1, j}, t + 1});
                fresh--;
            }
            if (i + 1 < n && !visited[i + 1][j] && grid[i + 1][j] == 1) {
                visited[i + 1][j] = true;
                q.push({{i + 1, j}, t + 1});
                fresh--;
            }
            if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1) {
                visited[i][j - 1] = true;
                q.push({{i, j - 1}, t + 1});
                fresh--;
            }
            if (j + 1 < m && !visited[i][j + 1] && grid[i][j + 1] == 1) {
                visited[i][j + 1] = true;
                q.push({{i, j + 1}, t + 1});
                fresh--;
            }
        }
        if (fresh == 0)
            return ans;
        return -1;
    }
};