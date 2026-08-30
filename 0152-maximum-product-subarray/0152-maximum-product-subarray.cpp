class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro = nums[0];
        int minpro = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int prevmax = maxpro;
            maxpro = max({prevmax * nums[i], minpro * nums[i], nums[i]});
            minpro = min({prevmax * nums[i], minpro * nums[i], nums[i]});
            ans = max(ans, maxpro);
        }
        return ans;
    }
};