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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        int count = countNodes(head);
        if(count == n){
            ListNode* temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
            return head;
        }
        int pos = count - n + 1;
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* curr = head;
        int cnt = 0;
        while (cnt < pos - 1){
            prev = curr;
            curr = curr -> next;
            cnt ++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        return head;
    }
    int countNodes (ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp -> next;
            cnt ++;
        }
        return cnt;
    }
};