class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        for(auto it : freq){
            if(it.second > nums.size() / 2) return it.first;
        }
        return -1;
    }
};