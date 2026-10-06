class Solution {
public:
    bool isThree(int n) {
        // int cnt = 0;
        // for(int i = 1; i <= n; i++){
        //     if(n % i == 0) cnt++;
        // }
        // return cnt == 3;

        int root = sqrt(n);
        if (root * root != n)
            return false;
        return prime(root);
    }
    bool prime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};