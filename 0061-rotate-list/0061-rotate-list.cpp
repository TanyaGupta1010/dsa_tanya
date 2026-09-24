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
        if (k == 0 || head == nullptr || head->next == nullptr)
            return head;

        int cnt = 1;
        ListNode* curr = head;

        while (curr->next) {
            cnt++;
            curr = curr->next;
        }

        k = k % cnt;

        if (k == 0)
            return head;

        curr->next = head;

        curr = head;

        int steps = cnt - k - 1;

        while (steps > 0) {
            curr = curr->next;
            steps--;
        }

        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};