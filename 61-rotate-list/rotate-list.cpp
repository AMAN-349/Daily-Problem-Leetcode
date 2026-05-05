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
    if (!head || k == 0) {
        return head;
    }

    int length = 1;
    ListNode* tail = head;

    // Calculate the length of the linked list and find the tail node
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Adjust k if it's greater than or equal to the length of the list
    k %= length;

    if (k == 0) {
        return head; // No rotation needed
    }

    // Find the new head and new tail nodes
    ListNode* newTail = head;
    for (int i = 0; i < length - k - 1; i++) {
        newTail = newTail->next;
    }

    // Perform the rotation
    ListNode* newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

};