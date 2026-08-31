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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        if(head->next==nullptr)
        {
            return {-1};
        }
        ListNode* curr=head->next;
        if(curr->next==nullptr)
        {
            return {-1,-1};
        }
        ListNode* nextnode=curr->next;

        int ind=1;

        int first=-1;
        int last=-1;

        int maxi=INT_MIN;
        int mini=INT_MAX;

        while(nextnode!=nullptr)
        {
            if((curr->val<prev->val && curr->val<nextnode->val) || (curr->val>prev->val && curr->val>nextnode->val))
            {
                if(first==-1)
                {
                    first=ind;
                }

                maxi=max(maxi,ind-first);

                if(last!=-1)
                mini=min(mini,ind-last);

                last=ind;
            }

            ind++;

            prev=curr;
            curr=nextnode;
            nextnode=nextnode->next;
        }

        if(maxi==INT_MIN || mini==INT_MAX)
        {
            return {-1,-1};
        }

        return {mini,maxi};


    }
};