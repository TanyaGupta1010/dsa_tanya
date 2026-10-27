class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(0, rooms, visited);
        for(int i = 0; i < n; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
    void dfs(int index, vector<vector<int>>& rooms, vector<bool>& visited){
        visited[index] = true;
        for(int key : rooms[index]){
            if(!visited[key]){
                dfs(key, rooms, visited);
            }
        }
    }
};