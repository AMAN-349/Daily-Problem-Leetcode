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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s(nums.begin(),nums.end());
        ListNode* temp=head;
        ListNode* newhead=head;
        ListNode* prev=NULL;
        while(temp!=NULL)
        {
            int value=temp->val;
            while (temp != NULL && s.find(temp->val) != s.end()) {
                temp = temp->next;
            }
            if (temp == NULL) break;
            if(prev)
            {
                prev->next=temp;
                prev=temp;
            }  
            else{
                newhead=temp;
                prev=temp;
            }
            temp=temp->next; 
        }
        if(prev) prev->next = NULL;
        return newhead;
    }
};