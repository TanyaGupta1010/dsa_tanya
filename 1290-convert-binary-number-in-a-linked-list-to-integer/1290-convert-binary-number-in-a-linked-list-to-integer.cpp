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
    int getDecimalValue(ListNode* head) {
        vector<int> bits;
        ListNode* temp = head;
        while(temp){
            bits.push_back(temp -> val);
            temp = temp -> next;
        }
        reverse(bits.begin(), bits.end());
        int result = 0;
        int power = 1;
        for(int bit : bits){
            result += bit * power;
            power *= 2;
        }
        return result;
    }
};