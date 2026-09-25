/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode* a = head1;
        ListNode* b = head2;
        while(a != b){
            if(a == nullptr){
                a = head2;
            }
            else a = a -> next;
            if(b == nullptr){
                b = head1;
            }
            else{
                b = b -> next;
            }
        }
        return a;
    }
};