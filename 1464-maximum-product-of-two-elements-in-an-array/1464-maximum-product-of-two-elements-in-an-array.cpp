class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        if(nums.size() >= 2){
            return (nums[0] - 1)*(nums[1] - 1);
        }return -1;
    }
};