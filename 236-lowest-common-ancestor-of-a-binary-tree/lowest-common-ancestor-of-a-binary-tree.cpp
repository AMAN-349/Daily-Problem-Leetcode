/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* find(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(!root || root==p || root==q)
        {
            return root;
        }
        TreeNode* left=find(root->left,p,q);
        TreeNode* right=find(root->right,p,q);
        if(left!=NULL && right!=NULL)
        {
            return root;
        }
        if(!left)
        {
            return right;
        }
        return left;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root,p,q);
    }
};