class Solution {
public:
    int countPrimes(int n) {
        // if(n < 2) return 0;
        // int cnt = 0;
        // for(int i = 2; i < n; i++){
        //     if(isprime(i)) cnt++;
        // }
        // return cnt;
        if(n < 2) return 0;
        vector<int> prime(n, true);
        prime[0] = false;
        prime[1] = false;
        for(int i = 2; i*i < n; i++){
            if(prime[i]){
                for(int j = i * i; j < n; j += i){
                    prime[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(prime[i]) cnt++;
        }
        return cnt;
    }
    // bool isprime(int n){
    //     // if(n < 2) return false;
    //     // for(int i = 2; i * i <= n; i++){
    //     //     if(n % i == 0) return false;
    //     // }
    //     // return true;
    // }
};