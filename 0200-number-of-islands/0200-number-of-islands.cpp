class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& visited, int m, int n) {
                if(i < 0 || i >= m || j < 0 || j >= n) return;
                if(grid[i][j] == '0') return;
                if(visited[i][j]) return;
                visited[i][j] = true;
                dfs(i - 1, j, grid, visited, m, n);
                dfs(i + 1, j, grid, visited, m, n);
                dfs(i, j - 1, grid, visited, m, n);
                dfs(i, j + 1, grid, visited, m, n);

             }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    dfs(i, j, grid, visited, m, n);
                }
            }
        }
        return ans;
    }
};