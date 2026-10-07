class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target > x + y) return false;
        int g = gcd(x,y);
        return target % g == 0;
    }
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
};