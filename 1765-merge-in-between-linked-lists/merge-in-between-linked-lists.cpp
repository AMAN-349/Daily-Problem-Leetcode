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
    ListNode* mergeInBetween(ListNode* head, int a, int b, ListNode* list2) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        int move1=a-1;
        int move2=b;
        while(move1)
        {
            temp1=temp1->next;
            move1--;
        }
        while(move2)
        {
            temp2=temp2->next;
            move2--;
        }
        if(temp2->next==NULL)
        {
            temp1->next=list2;
            return head;
        }
        else{
            ListNode* now=temp2->next;
            temp2->next=NULL;
            temp1->next=list2;
            ListNode* now2=list2;
            while(now2->next)
            {
                now2=now2->next;
            }
            now2->next=now;
        }
        return head;
        
    }
};