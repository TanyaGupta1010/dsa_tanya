class Solution {
public:
    vector<int> pse(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> nse(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> pge(vector<int>& nums) {
        int n = nums.size();
        vector<int> pge(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if (st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();
            st.push(i);
        }
        return pge;
    }
    vector<int> nge(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            if (st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();
            st.push(i);
        }
        return nge;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> prevsmaller = pse(nums);
        vector<int> nextsmaller = nse(nums);
        vector<int> prevgreater = pge(nums);
        vector<int> nextgreater = nge(nums);
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long leftgreater = i - prevgreater[i];
            long long rightgreater = nextgreater[i] - i;
            long long leftsmaller = i - prevsmaller[i];
            long long rightsmaller = nextsmaller[i] - i;
            long long maxcontribution =
                1LL * nums[i] * leftgreater * rightgreater;
            long long mincontribution =
                1LL * nums[i] * leftsmaller * rightsmaller;
            ans += maxcontribution - mincontribution;
        }
        return ans;
    }
};