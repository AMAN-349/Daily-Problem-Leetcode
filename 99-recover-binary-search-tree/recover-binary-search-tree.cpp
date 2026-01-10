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

    TreeNode* first=nullptr;
    TreeNode* prev;
    TreeNode* mid=nullptr;
    TreeNode* last=nullptr;

    void findInOrder(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        findInOrder(root->left);
        if(prev!=NULL && (root->val<prev->val))
        {
            if(first==NULL)
            {
                first=prev;
                mid=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        findInOrder(root->right);
    }

    void recoverTree(TreeNode* root) {
        //here we do it in TC:O(n)
        prev=new TreeNode(INT_MIN);
        findInOrder(root);
        if(first && last)
        {
            swap(first->val,last->val);
        }
        else if(first && mid){
            swap(first->val,mid->val);
        }
    }
};