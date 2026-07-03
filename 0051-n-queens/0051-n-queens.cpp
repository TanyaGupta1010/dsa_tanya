class Solution {
public:
    void addsolution(vector<vector<string>>& ans, int n,
                     vector<vector<char>>& board) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++) {
                s.push_back(board[i][j]);
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }
bool issafe(int row, int col, vector<vector<char>>& board, int n) {
    int x = row;
    int y = col;
    while (y >= 0) {
        if (board[x][y] == 'Q')
            return false;
        y--;
    }
    x = row;
    y = col;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 'Q')
            return false;
        y--;
        x--;
    }
    x = row;
    y = col;
    while (x < n && y >= 0) {
        if (board[x][y] == 'Q')
            return false;
        y--;
        x++;
    }
    return true;
}
void solve(vector<vector<string>>& ans, int n, vector<vector<char>>& board,
           int col) {
    // base case
    if (col == n) {
        addsolution(ans, n, board);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (issafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(ans, n, board, col + 1);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    solve(ans, n, board, 0);
    return ans;
}
};