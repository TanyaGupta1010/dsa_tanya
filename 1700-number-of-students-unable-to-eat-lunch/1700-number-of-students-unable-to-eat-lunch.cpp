class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int count = 0;
        for(int num : students){
            q.push(num);
        }
        int i = 0;
        while(!q.empty() && count < q.size()){
            if(q.front() == sandwiches[i]){
                q.pop();
                i++;
                count = 0;
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};