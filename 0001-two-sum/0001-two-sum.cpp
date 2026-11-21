class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        // for(int i = 0; i < nums.size(); i++){
        //     map[nums[i]] = i;
        // }
        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i];
            if(map.find(comp) != map.end()){
                return {i, map[comp]};
            }
            map[nums[i]] = i;
        }
        return {-1,-1};
    }
};