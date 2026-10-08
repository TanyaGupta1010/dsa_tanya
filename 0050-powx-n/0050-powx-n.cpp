class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            return 1.0 / solve(x, -exp);
        }
        return solve(x, exp);
    }
    double solve(double x, long long n) {
        if (n == 0)
            return 1;
        double half = solve(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        return half * half * x;
    }
};