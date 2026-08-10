class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int nodes = 0;
            int edgecount = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                nodes++;
                edgecount += adj[u].size();
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            edgecount /= 2;
            int requiededges = nodes * (nodes - 1) / 2;
            if (requiededges == edgecount)
                ans++;
        }
        return ans;
    }
};