class Solution {
public:
    vector<int> pse(vector<int>& heights) {
        stack<int> st;
        vector<int> ans(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int>& heights) {
        stack<int> st;
        vector<int> ans(heights.size());
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = heights.size();
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nse(heights);
        vector<int> prev = pse(heights);
        int ans = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            int width = next[i] - prev[i] - 1;
            int height = heights[i];
            ans = max(ans, width * height);
        }
        return ans;
    }
};