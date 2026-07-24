class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()) << 1;

        vector<bool> pairXor(mx, false);

        // All possible XORs of two elements
        for (int a : nums) {
            for (int b : nums) {
                pairXor[a ^ b] = true;
            }
        }

        vector<bool> ans(mx, false);

        // XOR each pair result with every element
        for (int x = 0; x < mx; x++) {
            if (!pairXor[x]) continue;

            for (int c : nums) {
                ans[x ^ c] = true;
            }
        }

        return count(ans.begin(), ans.end(), true);
    }
};