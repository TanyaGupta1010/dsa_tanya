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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            // Check if current value has duplicates
            if (curr->next != nullptr && curr->val == curr->next->val) {
                // Skip all nodes having the duplicate value
                while (curr->next != nullptr &&
                       curr->val == curr->next->val) {
                    curr = curr->next;
                }

                // Remove the entire duplicate sequence
                prev->next = curr->next;
            } 
            else {
                // Current node is unique
                prev = prev->next;
            }

            curr = curr->next;
        }

        return dummy.next;
    }
};