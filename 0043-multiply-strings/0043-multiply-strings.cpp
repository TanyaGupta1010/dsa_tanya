class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n = num1.size();
        int m = num2.size();
        int result[500] = {0};
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        string ans = "";
        for(int i = 0; i < n + m; i++){
            ans += char(result[i] + '0');
        }
        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);
        return ans;
    }
};