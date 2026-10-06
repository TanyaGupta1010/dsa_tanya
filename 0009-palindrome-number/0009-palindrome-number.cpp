class Solution {
public:
    bool isPalindrome(int x) {
        //two pointers
        // if(x < 0) return false;
        // string num = to_string(x);
        // int i = 0;
        // int j = num.size() - 1;
        // while(i <= j){
        //     if(num[i] != num[j]) return false;
        //     i++;
        //     j--;
        // }
        // return true;


        // reverse the original number and then compare the reversed and the original number
        if(x < 0) return false;
        int original = x;
        long long reverse = 0;
        while(x > 0){
            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x /= 10;
        }
        return (reverse == original);
    }
};