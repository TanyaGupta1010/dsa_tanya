class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i = 0; i < n; i++){
            pq.push({matrix[i][0], {i,0}});
        }
        for(int i = 0; i < k - 1; i++){
            auto curr = pq.top();
            pq.pop();
            int row = curr.second.first;
            int col = curr.second.second;
            if(col + 1 < n){
                pq.push({matrix[row][col + 1], {row, col + 1}});
            }
        }
        return pq.top().first;
    }
};