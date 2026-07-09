class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //mapping karenge pehle
        unordered_map<int,int> map;
        //creating empty stack
        stack<int> st;
        //iteration from n-1 to 0
        int n = nums2.size();
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                map[nums2[i]] = -1;
            }
            else{
                map[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(auto x : nums1){
            ans.push_back(map[x]);
        }
        return ans;
    }
};