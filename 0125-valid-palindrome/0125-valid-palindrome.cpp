class Solution {
public:
    bool isPalindrome(string s) { 
        return solve(s, 0, s.size() - 1); 
    }
    bool solve(string& s, int i, int j) {
        if (i > j)
            return true;
        while (i < j && !isalnum(s[i]))
            i++;
        while (i < j && !isalnum(s[j]))
            j--;
        if (tolower(s[i]) != tolower(s[j]))
            return false;
        return solve(s, i + 1, j - 1);
    }
};