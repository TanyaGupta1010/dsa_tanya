class Solution {
public:
    long long gcd (long long a, long long b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    long long lcm (long long a, long long b){
        return (a / gcd(a, b)) * b;
    }
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<long long> pregcd(n + 1, 0);
        vector<long long> prelcm(n + 1, 1);
        for(int i = 0; i < n; i++){
            pregcd[i + 1] = gcd(pregcd[i], nums[i]);
            prelcm[i + 1] = lcm(prelcm[i], nums[i]);
        }
        vector<long long> suffgcd(n + 1, 0);
        vector<long long> sufflcm(n + 1, 1);
        for(int i = n - 1; i >= 0; i--){
            suffgcd[i] = gcd(suffgcd[i + 1], nums[i]);
            sufflcm[i] = lcm(sufflcm[i + 1], nums[i]);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long g = gcd(pregcd[i] , suffgcd[i + 1]);
            long long l = lcm(prelcm[i] , sufflcm[i + 1]);
            ans = max(ans, g * l);
        }
        ans = max(ans, pregcd[n] * prelcm[n]);
        return ans;
    }
};