class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    ans = max(ans, dfs(grid, i, j, visited));
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0 || visited[row][col]) return 0;
        visited[row][col] = true;
        return 1 + dfs(grid, row + 1, col, visited) +
        dfs(grid, row - 1, col, visited) + 
        dfs(grid, row, col - 1, visited) +
        dfs(grid, row, col + 1, visited);
    }
};