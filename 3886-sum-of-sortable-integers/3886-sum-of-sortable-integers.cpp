
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            int prevMax = -1;

            for (int start = 0; start < n; start += k) {
                int mn = nums[start];
                int mx = nums[start];
                int descents = 0;

                for (int j = 0; j < k; j++) {
                    int idx = start + j;
                    int next = start + (j + 1) % k;

                    mn = min(mn, nums[idx]);
                    mx = max(mx, nums[idx]);

                    if (nums[idx] > nums[next]) {
                        descents++;
                    }
                }

                // A block must be sortable by cyclic rotation.
                if (descents > 1) {
                    valid = false;
                    break;
                }

                // Consecutive sorted blocks must be compatible.
                if (start > 0 && prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};
