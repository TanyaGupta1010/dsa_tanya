class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int minnum = nums[0];
        int maxnum = nums[0];
        for(int num : nums){
            if(num > maxnum) maxnum = num;
            if (num < minnum) minnum = num;
        }
        int result = gcd(maxnum, minnum);
        return result;
    }
};