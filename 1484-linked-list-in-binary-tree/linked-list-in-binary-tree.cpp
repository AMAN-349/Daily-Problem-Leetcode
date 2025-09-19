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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool find(ListNode* temp, TreeNode* root)
    {
        if(temp== nullptr)
        {
            return true;
        }
        if(root== nullptr)
        {
            return false;
        }
        if(temp->val != root->val)
        {
            return false;
        }
        return find(temp->next, root->left) || find(temp->next, root->right);
        
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        return find(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};