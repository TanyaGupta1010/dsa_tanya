class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> st;
        for(char c : num){
            while(!st.empty() && st.top() > c && k > 0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while(i < ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);
        if(ans.empty()) return "0";
        return ans;
    }
};