class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int x, int y,
               int index, vector<vector<bool>>& visited) {
        // basecase
        if (index == word.size() - 1)
            return true;
        // 4 movements - down, left, right, up
        visited[x][y] = true;
        // down
        if (issafe(x + 1, y, board, visited, word, index)) {
            if (solve(board, word, x + 1, y, index + 1, visited))
                return true;
        }
        // left
        if (issafe(x, y - 1, board, visited, word, index)) {
            if (solve(board, word, x, y - 1, index + 1, visited))
                return true;
        }
        // right
        if (issafe(x, y + 1, board, visited, word, index)) {
            if (solve(board, word, x, y + 1, index + 1, visited))
                return true;
        }
        // up
        if (issafe(x - 1, y, board, visited, word, index)) {
            if (solve(board, word, x - 1, y, index + 1, visited))
                return true;
        }
        // backtrack
        visited[x][y] = false;
        return false;
    }
    bool issafe(int newx, int newy, vector<vector<char>>& board,
                vector<vector<bool>>& visited, string& word, int index) {
        int m = board.size();
        int n = board[0].size();
        if ((newx >= 0 && newx < m) && (newy >= 0 && newy < n) &&
            visited[newx][newy] != 1 && board[newx][newy] == word[index + 1])
            return true;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    if (solve(board, word, i, j, 0, visited))
                        return true;
                }
            }
        }
        return false;
    }
};