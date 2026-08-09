class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            vector<int> path = q.front();
            q.pop();
            int node = path.back();
            if(node == graph.size() - 1){
                ans.push_back(path);
                continue;
            }
            for(int next : graph[node]){
                vector<int> newpath = path;
                newpath.push_back(next);
                q.push(newpath);
            }
        }
        return ans;
    }
};