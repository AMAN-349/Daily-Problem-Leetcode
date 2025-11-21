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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd=new ListNode();
        ListNode* even=new ListNode();
        ListNode* tempodd=odd;
        ListNode* tempeven=even;
        int it=0;

        ListNode* temp=head;
        while(head)
        {
            if((it)%2!=0)
            {
                tempeven->next=temp;
                tempeven=temp;
                head=temp->next;
                temp->next=NULL;
                temp=head;
            }
            else{
                tempodd->next=temp;
                tempodd=temp;
                head=temp->next;
                temp->next=NULL;
                temp=head;
            }
            it++;
        }
        tempodd->next=even->next;
        return odd->next;
    }
};