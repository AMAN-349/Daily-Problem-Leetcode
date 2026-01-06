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

    ListNode* merge(ListNode* h1,ListNode* h2)
    {
        if(!h1)
        {
            return h2;
        }
        if(!h2)
        {
            return h1;
        }
        ListNode* head;
        ListNode* tail;
        ListNode* p1=h1;
        ListNode* p2=h2;
        if(h1->val<=h2->val)
        {
            head=h1;
            tail=h1;
            p1=p1->next;
        }
        else{
            head=h2;
            tail=h2;
            p2=p2->next;
        }
        while(p1 && p2)
        {
            if(p1->val <= p2->val)
            {
                tail->next=p1;
                p1=p1->next;
            }
            else{
                tail->next=p2;
                p2=p2->next;
            }
            tail=tail->next;
        }
        while(p1)
        {
            tail->next=p1;
            p1=p1->next;
            tail=tail->next;
        }
        while(p2)
        {
            tail->next=p2;
            p2=p2->next;
            tail=tail->next;
        }
        return head;
    }

    ListNode* find(int l,int r,vector<ListNode*>& list)
    {
        if(l==r)
        {
            return list[l];
        }
        int m=(l+r)/2;
        ListNode* h1=find(l,m,list);
        ListNode* h2=find(m+1,r,list);
        return merge(h1,h2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
        {
            return NULL;
        }
        int l=0;
        int r=n-1;
        return find(l,r,lists);
    }
};