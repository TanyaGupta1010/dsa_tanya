class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<pair<int, int>> v;
        
        // Store {value, original_index}
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        
        // Sort according to values
        sort(v.begin(), v.end());
        
        vector<int> ans(n);
        
        int i = 0;
        
        while (i < n) {
            int j = i;
            
            // Find a group where consecutive values
            // can be swapped indirectly
            while (j + 1 < n && v[j + 1].first - v[j].first <= limit) {
                j++;
            }
            
            // Collect indices of this group
            vector<int> indices;
            vector<int> values;
            
            for (int k = i; k <= j; k++) {
                indices.push_back(v[k].second);
                values.push_back(v[k].first);
            }
            
            // Smallest values should go to smallest indices
            sort(indices.begin(), indices.end());
            
            for (int k = 0; k < indices.size(); k++) {
                ans[indices[k]] = values[k];
            }
            
            i = j + 1;
        }
        
        return ans;
    }
};