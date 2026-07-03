class Solution {
public:
    bool issafe(int row, int col, vector<vector<int>> &board, int n){
        int x = row;
        int y = col;
        while(y >= 0){
            if(board[x][y] == 1)
            return false;
            y--;
        }
        x = row;
        y = col;
        while(x >= 0 && y >= 0){
            if(board[x][y] == 1)
            return false;
            y--;
            x--;
        }
        x = row;
        y = col;
        while(x < n && y >= 0){
            if(board[x][y] == 1)
            return false;
            y--;
            x++;
        }
        return true;
    }
    void solve(int &ans, vector<vector<int>> &board, int n, int col){
        //basecase
        if(col == n){
            ans++;
            return;
        }
        for(int row = 0; row < n; row++){
            if(issafe(row, col, board, n)){
                board[row][col] = 1;
                solve(ans, board, n, col + 1);
                board[row][col] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        vector<vector<int>> board(n, vector<int>(n, 0));
        solve(ans, board, n, 0);
        return ans;
    }
};