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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int n = 0;
    ListNode* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }

    int sizes = n / k;
    int rem = n % k;

    vector<ListNode*> ans;
    temp = head;

    for (int i = 0; i < k; i++) {
        ans.push_back(temp);
        int partSize = sizes + (rem > 0 ? 1 : 0);
        if (rem > 0) rem--;

        for (int j = 0; j < partSize - 1 && temp; j++) {
            temp = temp->next;
        }

        if (temp) {
            ListNode* nextPart = temp->next;
            temp->next = NULL;
            temp = nextPart;
        }
    }
    return ans;
}

};