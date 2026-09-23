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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr || k== 0) return head;
        int cnt = 1;
        ListNode* temp = head;
        while(temp -> next != nullptr){
            temp = temp -> next;
            cnt ++;
        }
        k = k % cnt;
        if(k == 0) return head;
        temp -> next = head;
        ListNode* newtail = head;
        int step = cnt - k - 1;
        while(step > 0){
            // step --;
            newtail = newtail -> next;
            step --;
        }
        ListNode* newhead = newtail -> next;
        newtail -> next = nullptr;
        return newhead;
    }
};