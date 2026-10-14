class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = first(nums, target);
        int b = second(nums, target);
        return {a,b};
    }
    int first (vector<int>& nums, int target){
        int ans = -1;
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }
            if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
    int second (vector<int>& nums, int target){
        int ans = -1;
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};