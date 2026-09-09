class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++){
            if(map.find(s[right]) != map.end() && map[s[right]] >= left){
                left = map[s[right]] + 1;
            }
            map[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};