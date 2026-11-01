class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> pq;
        for (vector<int> p : points) {
            pq.push({p[0], p[1]});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
    }
    struct Comparator {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            int d1 = a.first * a.first + a.second * a.second;
            int d2 = b.first * b.first + b.second * b.second;
            return d1 < d2;
        }
    };
};