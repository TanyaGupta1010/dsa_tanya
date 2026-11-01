class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;
        for(int x : nums){
            if(x > first){
                third = second;
                second = first;
                first = x;
            }
            else if( x < first && x > second){
                third = second;
                second = x;
            }
            else if( x < second && x > third){
                third = x;
            }
        }
        if(third == LLONG_MIN) return first;
        return third;
    }
};