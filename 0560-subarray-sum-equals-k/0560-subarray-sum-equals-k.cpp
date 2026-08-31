class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        // Prefix sum 0 has occurred once
        mp[0] = 1;
        
        int prefixSum = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            // Update current prefix sum
            prefixSum += nums[i];
            
            // Required previous prefix sum
            int needed = prefixSum - k;
            
            // If it exists, add its frequency
            if (mp.find(needed) != mp.end()) {
                count += mp[needed];
            }
            
            // Store/update current prefix sum frequency
            mp[prefixSum]++;
        }
        
        return count;
    }
};