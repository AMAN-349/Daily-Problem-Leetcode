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
        vector<int> v;
        int ans=0;
        while(head)
        {
            v.push_back(head->val);
            head=head->next;
        }
        int n=v.size();
        for(auto i:v)
        {
            n--;
            ans+=(i*(pow(2,n)));
        }
        return ans;
    }
};