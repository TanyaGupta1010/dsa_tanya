class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long ans = 0;
        long long prev = 0;
        for (int i = 0; i < n; i++) {
            long long curr = 1LL * target[i] - nums[i];
            if ((curr >= 0 && prev >= 0) || (curr <= 0 && prev <= 0)) {
                if (abs(curr) > abs(prev))
                    ans += abs(curr) - abs(prev);
            } else {
                ans += abs(curr);
            }
            prev = curr;
        }
        return ans;
    }
};