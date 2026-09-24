/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;
        ListNode* curr = head;
        while(curr && top <= bottom && left <= right){
            //top row
            for(int i = left; i <= right && curr; i++){
                ans[top][i] = curr -> val;
                curr = curr -> next;
            }
            top++;
            //right column
            for(int i = top; i <= bottom && curr; i++){
                ans[i][right] = curr -> val;
                curr = curr -> next;
            }
            right--;
            //bottom row
            for(int i = right; i >= left && curr; i--){
                ans[bottom][i] = curr -> val;
                curr = curr -> next;
            }
            bottom--;
            //left column
            for(int i = bottom; i >= top && curr ; i--){
                ans[i][left] = curr -> val;
                curr = curr -> next;
            }
            left++;
        }
        return ans;
    }
};