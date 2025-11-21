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
        for (ListNode *cur = head, *prev = 0; cur; cur = cur->next)
            if (prev && cur->val == prev->val) prev->next = cur->next; else prev = cur;
        return head;
    }
};