class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            vector<int>& last = answer.back();
            if(intervals[i][0] <= last[1]){
                last[1] = max(intervals[i][1], last[1]);
            }
            else answer.push_back(intervals[i]);
        }
        return answer;
    }
};