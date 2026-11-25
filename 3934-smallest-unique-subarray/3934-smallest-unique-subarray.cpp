class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        // Double hashing parameters to prevent hash collisions
        const long long B1 = 1315423911LL, M1 = 1000000007LL;
        const long long B2 = 13331LL,      M2 = 1000000009LL;
        
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        
        // Precompute powers and prefix hashes
        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (p1[i] * B1) % M1;
            p2[i + 1] = (p2[i] * B2) % M2;
            h1[i + 1] = (h1[i] * B1 + nums[i]) % M1;
            h2[i + 1] = (h2[i] * B2 + nums[i]) % M2;
        }
        
        // Lambda to check if a unique subarray of length `len` exists
        auto hasUnique = [&](int len) -> bool {
            unordered_map<long long, int> freq;
            freq.reserve(n - len + 1);
            
            for (int i = 0; i <= n - len; ++i) {
                long long subH1 = (h1[i + len] - (h1[i] * p1[len]) % M1 + M1) % M1;
                long long subH2 = (h2[i + len] - (h2[i] * p2[len]) % M2 + M2) % M2;
                
                // Combine both 32-bit hashes into a single 64-bit key
                long long combinedHash = (subH1 << 32) | subH2;
                freq[combinedHash]++;
            }
            
            for (const auto& [hashVal, count] : freq) {
                if (count == 1) return true;
            }
            return false;
        };
        
        // Binary search on the subarray length
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid length
            } else {
                low = mid + 1;  // Need a longer subarray
            }
        }
        
        return ans;
    }
};