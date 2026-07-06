class Solution {
public:
    void solve(int& ans, string& output, string tiles, vector<bool>& visited) {
        if (output.size() > 0) {
            ans++;
        }
        for (int i = 0; i < tiles.size(); i++) {
            if (visited[i])
                continue;
            if (i > 0 && tiles[i] == tiles[i - 1] && !visited[i - 1])
                continue;
            visited[i] = true;
            output.push_back(tiles[i]);
            solve(ans, output, tiles, visited);
            output.pop_back();
            visited[i] = false;
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        string output;
        int ans = 0;
        vector<bool> visited(tiles.size(), false);
        solve(ans, output, tiles, visited);
        return ans;
    }
};