class Solution {
public:
    int search(vector<int>& nums, int target) {
        return solve(nums, 0, nums.size() - 1, target);
    }
    int solve(vector<int>& nums, int low, int high, int target){
        if(low > high) return -1;
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target){
            return solve(nums, low, mid - 1, target);
        }
        return solve(nums, mid + 1, high, target);
    }
};