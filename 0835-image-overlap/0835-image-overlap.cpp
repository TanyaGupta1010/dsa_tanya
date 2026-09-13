class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> ones1, ones2;

        int n = img1.size();

        // Store positions of all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    ones1.push_back({i, j});

                if (img2[i][j] == 1)
                    ones2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> mp;
        int ans = 0;

        // Find translation required for every pair
        for (auto a : ones1) {
            for (auto b : ones2) {
                int dx = a.first - b.first;
                int dy = a.second - b.second;

                ans = max(ans, ++mp[{dx, dy}]);
            }
        }

        return ans;
    }
};