class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    return dfs(grid, i, j, visited);
                }
            }
        }
        return 0;
    }
    int dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) return 1;
        if(visited[row][col]) return 0;
        visited[row][col] = true;
        int ans = 0;
        ans += dfs(grid, row + 1, col, visited);
        ans += dfs(grid, row - 1, col, visited);
        ans += dfs(grid, row, col + 1, visited);
        ans += dfs(grid, row, col - 1, visited);
        return ans;
    }
};