class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // suffix minimum
        vector<int> suf(n);
        suf[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            suf[i] = min(nums[i], suf[i + 1]);
        }

        // prefix maximum + check
        int prefMax = INT_MIN;

        for (int i = 0; i < n; ++i) {
            prefMax = max(prefMax, nums[i]);

            // instability = max(nums[0..i]) - min(nums[i..n-1])
            if (prefMax - suf[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};