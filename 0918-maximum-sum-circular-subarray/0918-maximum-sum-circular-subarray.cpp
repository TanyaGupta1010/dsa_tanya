class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        int currMax = 0;
        int maxSum = nums[0];

        int currMin = 0;
        int minSum = nums[0];

        for (int x : nums) {

            // Kadane for maximum
            currMax = max(x, currMax + x);
            maxSum = max(maxSum, currMax);

            // Kadane for minimum
            currMin = min(x, currMin + x);
            minSum = min(minSum, currMin);

            total += x;
        }

        // All elements are negative
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};