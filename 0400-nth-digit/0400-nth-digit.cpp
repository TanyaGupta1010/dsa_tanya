class Solution {
public:
    int findNthDigit(int n) {
        long long digit = 1;
        long long count = 9;
        long long start = 1;
        while(n > digit * count){
            n -= digit * count;
            digit++;
            count *= 10;
            start *= 10;
        }
        long long num = start + (n - 1)/digit;
        int index = (n - 1) % digit;
        string a = to_string(num);
        return a[index] - '0';

    }
};